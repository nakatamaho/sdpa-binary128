/*
 * Copyright (c) 2008-2021
 *      Nakata, Maho
 *      All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include <mpblas__Float128.h>
#include <mplapack__Float128.h>

_Float128 Rlanst(const char *norm, mplapackint const n, _Float128 *d, _Float128 *e) {
    _Float128 return_value = 0.0;
    //
    //  -- LAPACK auxiliary routine --
    //  -- LAPACK is a software package provided by Univ. of Tennessee,    --
    //  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
    //
    //     .. Scalar Arguments ..
    //     ..
    //     .. Array Arguments ..
    //     ..
    //
    //  =====================================================================
    //
    //     .. Parameters ..
    //     ..
    //     .. Local Scalars ..
    //     ..
    //     .. External Functions ..
    //     ..
    //     .. External Subroutines ..
    //     ..
    //     .. Intrinsic Functions ..
    //     ..
    //     .. Executable Statements ..
    //
    const _Float128 zero = 0.0;
    _Float128 anorm = 0.0;
    mplapackint i = 0;
    _Float128 sum = 0.0;
    _Float128 scale = 0.0;
    const _Float128 one = 1.0;
    if (n <= 0) {
        anorm = zero;
    } else if (Mlsame__Float128(norm, "M")) {
        //
        //        Find std::max(abs(A(i,j))).
        //
        anorm = abs(d[n - 1]);
        for (i = 1; i <= n - 1; i = i + 1) {
            sum = abs(d[i - 1]);
            if (anorm < sum || Risnan(sum)) {
                anorm = sum;
            }
            sum = abs(e[i - 1]);
            if (anorm < sum || Risnan(sum)) {
                anorm = sum;
            }
        }
    } else if (Mlsame__Float128(norm, "O") || (Mlsame__Float128(norm, "1")) || Mlsame__Float128(norm, "I")) {
        //
        //        Find norm1(A).
        //
        if (n == 1) {
            anorm = abs(d[1 - 1]);
        } else {
            anorm = abs(d[1 - 1]) + abs(e[1 - 1]);
            sum = abs(e[(n - 1) - 1]) + abs(d[n - 1]);
            if (anorm < sum || Risnan(sum)) {
                anorm = sum;
            }
            for (i = 2; i <= n - 1; i = i + 1) {
                sum = abs(d[i - 1]) + abs(e[i - 1]) + abs(e[(i - 1) - 1]);
                if (anorm < sum || Risnan(sum)) {
                    anorm = sum;
                }
            }
        }
    } else if ((Mlsame__Float128(norm, "F")) || (Mlsame__Float128(norm, "E"))) {
        //
        //        Find normF(A).
        //
        scale = zero;
        sum = one;
        if (n > 1) {
            Rlassq(n - 1, e, 1, scale, sum);
            sum = 2 * sum;
        }
        Rlassq(n, d, 1, scale, sum);
        anorm = scale * sqrt(sum);
    }
    //
    return_value = anorm;
    return return_value;
    //
    //     End of Rlanst
    //
}
