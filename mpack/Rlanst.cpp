/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Nakata, Maho
 * 
 * $Id: Rlanst.cpp,v 1.2 2009/09/12 07:59:10 nakatamaho Exp $ 
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

#include <mblas___float128.h>
#include <mlapack___float128.h>

#ifndef mpack_max
#define mpack_max(a,b) (((a)>(b))?(a):(b))
#endif
#ifndef min
#define min(a,b) (((a)<(b))?(a):(b))
#endif

__float128
Rlanst(const char *norm, mpackint n, __float128 * d, __float128 * e)
{
    mpackint i;
    __float128 anorm, scale, sum;
    __float128 Zero = 0.0;
    __float128 One = 1.0;
    __float128 mtmp1, mtmp2;

    if (n <= 0) {
	anorm = Zero;
    } else if (Mlsame___float128(norm, "M")) {
//Find mpack_max(abs(A(i,j))).
	anorm = abs(d[n - 1]);
	for (i = 0; i < n - 1; i++) {
	    mtmp1 = abs(d[i]);
	    mtmp2 = abs(e[i]);
	    anorm = mpack_max(anorm, mtmp1);
	    anorm = mpack_max(anorm, mtmp2);
//          anorm = mpack_max(anorm, abs(d[i]));
//          anorm = mpack_max(anorm, abs(e[i]));
	}
    } else if (Mlsame___float128(norm, "O") || Mlsame___float128(norm, "1") || Mlsame___float128(norm, "I")) {
	if (n == 1) {
	    anorm = abs(d[0]);
	} else {
	    anorm = mpack_max(abs(d[0]) + abs(e[0]), abs(e[n - 2]) + abs(d[n - 1]));
	    for (i = 1; i < n - 1; i++) {
		anorm = mpack_max(anorm, abs(d[i]) + abs(e[i]) + abs(e[i - 1]));
	    }
	}
    } else if (Mlsame___float128(norm, "F") || Mlsame___float128(norm, "E")) {
//Find normF(A).
	scale = Zero;
	sum = One;
	if (n > 1) {
	    Rlassq(n - 1, e, 1, &scale, &sum);
	    sum *= 2.0;
	}
	Rlassq(n, d, 1, &scale, &sum);
	anorm = scale * sqrtq(sum);
    }
    return anorm;
}
