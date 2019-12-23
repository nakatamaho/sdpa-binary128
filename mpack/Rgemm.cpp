/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Nakata, Maho
 * 
 * $Id: Rgemm.cpp,v 1.5 2009/09/25 04:00:39 nakatamaho Exp $ 
 *
 * MPACK - multiple precision arithmetic library
 *
 * This file is part of MPACK.
 *
 * MPACK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3
 * only, as published by the Free Software Foundation.
 *
 * MPACK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU Lesser General Public License
 * version 3 along with MPACK.  If not, see
 * <http://www.gnu.org/licenses/lgpl.html>
 * for a copy of the LGPLv3 License.
 *
 ************************************************************************/
/*
Copyright (c) 1992-2007 The University of Tennessee.  All rights reserved.

$COPYRIGHT$

Additional copyrights may follow

$HEADER$

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

- Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer. 
  
- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer listed
  in this license in the documentation and/or other materials
  provided with the distribution.
  
- Neither the name of the copyright holders nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.
  
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
*/

/*
Based on http://www.netlib.org/blas/dgemm.f
Rgemm performs one of the matrix-matrix operations
 C := alpha*op(A)*op(B) + beta*C,
where op(X) is one of
 op(X) = X or op(X) = X',
alpha and beta are scalars, and A, B and C are matrices, with op( A )
an m by k matrix, op(B) a k by n matrix and C an m by n matrix.
*/

#include <mblas___float128.h>

void
Rgemm(const char *transa, const char *transb, mpackint m, mpackint n, mpackint k,
    __float128 alpha, __float128 * A, mpackint lda, __float128 * B, mpackint ldb,
    __float128 beta, __float128 * C, mpackint ldc)
{
    mpackint nota, notb;
    mpackint nrowa, ncola;
    mpackint nrowb;
    mpackint info;

    __float128 Zero = 0.0, One = 1.0;
    __float128 temp;

    nota = Mlsame___float128(transa, "N");
    notb = Mlsame___float128(transb, "N");

    if (nota) {
	nrowa = m;
	ncola = k;
    } else {
	nrowa = k;
	ncola = m;
    }
    if (notb) {
	nrowb = k;
    } else {
	nrowb = n;
    }

    //Test the input parameters.
    info = 0;
    if (!nota && (!Mlsame___float128(transa, "C")) && (!Mlsame___float128(transa, "T")))
	info = 1;
    else if (!notb && (!Mlsame___float128(transb, "C")) && (!Mlsame___float128(transb, "T")))
	info = 2;
    else if (m < 0)
	info = 3;
    else if (n < 0)
	info = 4;
    else if (k < 0)
	info = 5;
    else if (lda < mpack_max((mpackint) 1, nrowa))
	info = 8;
    else if (ldb < mpack_max((mpackint) 1, nrowb))
	info = 10;
    else if (ldc < mpack_max((mpackint) 1, m))
	info = 13;
    if (info != 0) {
	Mxerbla___float128("Rgemm ", info);
	return;
    }
//Quick return if possible.
    if ((m == 0) || (n == 0) || (((alpha == Zero) || (k == 0))
	    && (beta == One)))
	return;

//And when alpha == 0.0
    if (alpha == Zero) {
	if (beta == Zero) {
	    for (mpackint j = 0; j < n; j++) {
		for (mpackint i = 0; i < m; i++) {
		    C[i + j * ldc] = Zero;
		}
	    }
	} else {
	    for (mpackint j = 0; j < n; j++) {
		for (mpackint i = 0; i < m; i++) {
		    C[i + j * ldc] = beta * C[i + j * ldc];
		}
	    }
	}
	return;
    }
//Start the operations.
    if (notb) {
	if (nota) {
	    //Form C := alpha*A*B + beta*C.
	    for (mpackint j = 0; j < n; j++) {
		if (beta == Zero) {
		    for (mpackint i = 0; i < m; i++) {
			C[i + j * ldc] = Zero;
		    }
		} else if (beta != One) {
		    for (mpackint i = 0; i < m; i++) {
			C[i + j * ldc] = beta * C[i + j * ldc];
		    }
		}
		for (mpackint l = 0; l < k; l++) {
		    if (B[l + j * ldb] != Zero) {
			temp = alpha * B[l + j * ldb];
			for (mpackint i = 0; i < m; i++) {
			    C[i + j * ldc] =
				C[i + j * ldc] + temp * A[i + l * lda];
			}
		    }
		}
	    }
	} else {
//Form  C := alpha*A'*B + beta*C.
	    for (mpackint j = 0; j < n; j++) {
		for (mpackint i = 0; i < m; i++) {
		    temp = Zero;
		    for (mpackint l = 0; l < k; l++) {
			temp = temp + A[l + i * lda] * B[l + j * ldb];
		    }
		    if (beta == Zero)
			C[i + j * ldc] = alpha * temp;
		    else
			C[i + j * ldc] = alpha * temp + beta * C[i + j * ldc];
		}
	    }
	}
    } else {
	if (nota) {
//Form  C := alpha*A*B' + beta*C.
	    for (mpackint j = 0; j < n; j++) {
		if (beta == Zero) {
		    for (mpackint i = 0; i < m; i++) {
			C[i + j * ldc] = Zero;
		    }
		} else if (beta != One) {
		    for (mpackint i = 0; i < m; i++) {
			C[i + j * ldc] = beta * C[i + j * ldc];
		    }
		}
		for (mpackint l = 0; l < k; l++) {
		    if (B[j + l * ldb] != Zero) {
			temp = alpha * B[j + l * ldb];
			for (mpackint i = 0; i < m; i++) {
			    C[i + j * ldc] =
				C[i + j * ldc] + temp * A[i + l * lda];
			}
		    }
		}
	    }
	} else {
//Form  C := alpha*A'*B' + beta*C.
	    for (mpackint j = 0; j < n; j++) {
		for (mpackint i = 0; i < m; i++) {
		    temp = Zero;
		    for (mpackint l = 0; l < k; l++) {
			temp = temp + A[l + i * lda] * B[j + l * ldb];
		    }
		    if (beta == Zero)
			C[i + j * ldc] = alpha * temp;
		    else
			C[i + j * ldc] = alpha * temp + beta * C[i + j * ldc];
		}
	    }
	}
    }
    return;
}
