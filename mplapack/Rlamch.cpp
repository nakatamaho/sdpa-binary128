/*
 * Copyright (c) 2008-2023
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
#include <mpblas.h>
#include <mplapack.h>

#if defined ___MPLAPACK_BUILD_WITH__FLOAT128___ && defined ___MPLAPACK_WANT_LIBQUADMATH___
#include <quadmath.h>
#else
#include <float.h>
#endif

#include <stdio.h>

//"E" denots we always calculate relative machine precision (e).
// where 1+e = 1, minimum of e.
_Float128 RlamchE__Float128(void) {
#if defined ___MPLAPACK_WANT_LIBQUADMATH___
    return FLT128_EPSILON;
#elif defined ___MPLAPACK_LONGDOUBLE_IS_BINARY128___
    return 1.92592994438723585305597794258492732e-34L;
#else
    return 1.92592994438723585305597794258492732e-34Q;
#endif
}

//"S" denots we always calculate `safe minimum, such that 1/sfmin does not overflow'.
// cf.http://www.netlib.org/blas/dlamch.f
_Float128 RlamchS__Float128(void) {
// IEEE 754 2008 binary128: emin = -16382
// 2^{-16382} = 3.36210314311209350626267781732175260e-4932Q
#if defined ___MPLAPACK_WANT_LIBQUADMATH___
    return FLT128_MIN;
#elif defined ___MPLAPACK_LONGDOUBLE_IS_BINARY128___
    return 3.36210314311209350626267781732175260e-4932L;
#else
    return 3.36210314311209350626267781732175260e-4932Q;
#endif

    static _Float128 eps;
    static int called = 0;
    if (called)
        return eps;
    eps = 1.0;
    // We all know double is the IEEE 754 2008 binary128 format has 113bit significant digits
    for (int i = 0; i < 16383; i++) {
        eps = eps / 2.0;
    }
    called = 1;
}

//"B" base  = base of the machine
// cf.http://www.netlib.org/blas/dlamch.f
_Float128 RlamchB__Float128(void) {
    _Float128 two;
    two = 2.0;
    return two;
}

//"P" prec = eps*base
// cf.http://www.netlib.org/blas/dlamch.f
_Float128 RlamchP__Float128(void) {
    _Float128 base, eps, prec;

    base = RlamchB__Float128();
    eps = RlamchE__Float128();
    prec = eps * base;
    return prec;
}

//"N" t = number of digits in mantissa
// cf.http://www.netlib.org/blas/dlamch.f
_Float128 RlamchN__Float128(void) {
#if defined ___MPLAPACK_WANT_LIBQUADMATH___
    return (_Float128)FLT128_MANT_DIG; // 113
#else
    return (_Float128)113;
#endif
}

//"R" rnd   = 1.0 when rounding occurs in addition, 0.0 otherwise
// cf.http://www.netlib.org/blas/dlamch.f
_Float128 RlamchR__Float128(void) {
    _Float128 mtmp;
    mtmp = 1.0;
    return mtmp;
}

//"M"
// cf.http://www.netlib.org/blas/dlamch.f
_Float128 RlamchM__Float128(void) {
    // the exponent of IEEE 754 2008 binary64 is -16382.
    // then -16382 + 1 = -16381
#if defined ___MPLAPACK_WANT_LIBQUADMATH___
    return FLT128_MIN_EXP;
#elif defined ___MPLAPACK_LONGDOUBLE_IS_BINARY128___
    return (-16381);
#else
    return (-16381);
#endif
}

//"U"
// cf.http://www.netlib.org/blas/dlamch.f
_Float128 RlamchU__Float128(void) {
#if defined ___MPLAPACK_WANT_LIBQUADMATH___
    return FLT128_MIN;
#elif defined ___MPLAPACK_LONGDOUBLE_IS_BINARY128___
    return 3.36210314311209350626267781732175260e-4932L;
#else
    return 3.36210314311209350626267781732175260e-4932Q;
#endif

    // 2^{-16382+1} minimum exponent
    static double eps;
    static int called = 0;
    if (called)
        return eps;
    eps = 1.0;
    // We all know double is the IEEE 754 2008 binary128 format has 113bit significant digits
    for (int i = 0; i < 16382; i++) {
        eps = eps / 2.0;
    }
    called = 1;
    return eps;
}

//"L"
// cf.http://www.netlib.org/blas/dlamch.f
_Float128 RlamchL__Float128(void) {
    //+16383 in IEEE 754 2008 binary128
    // then 16383 + 1 = 16384
#if defined ___MPLAPACK_WANT_LIBQUADMATH___
    return FLT128_MAX_EXP;
#else
    return 16384;
#endif
}

//"O"
// cf.http://www.netlib.org/blas/dlamch.f
_Float128 RlamchO__Float128(void) {
    // 1.18973149535723176508575932662800702e4932Q in IEEE 754 2008 binary128.
#if defined ___MPLAPACK_WANT_LIBQUADMATH___
    return FLT128_MAX;
#elif defined ___MPLAPACK_LONGDOUBLE_IS_BINARY128___
    return 1.18973149535723176508575932662800702e4932L;
#else
    return 1.18973149535723176508575932662800702e4932Q;
#endif
}

//"Z" :dummy
// cf.http://www.netlib.org/blas/dlamch.f
_Float128 RlamchZ__Float128(void) {
    _Float128 mtemp = 0.0;
    return mtemp;
}

_Float128 Rlamch__Float128(const char *cmach) {
    if (Mlsame(cmach, "E"))
        return RlamchE__Float128();
    if (Mlsame(cmach, "S"))
        return RlamchS__Float128();
    if (Mlsame(cmach, "B"))
        return RlamchB__Float128();
    if (Mlsame(cmach, "P"))
        return RlamchP__Float128();
    if (Mlsame(cmach, "N"))
        return RlamchN__Float128();
    if (Mlsame(cmach, "R"))
        return RlamchR__Float128();
    if (Mlsame(cmach, "M"))
        return RlamchM__Float128();
    if (Mlsame(cmach, "U"))
        return RlamchU__Float128();
    if (Mlsame(cmach, "L"))
        return RlamchL__Float128();
    if (Mlsame(cmach, "O"))
        return RlamchO__Float128();

    Mxerbla("Rlamch", 1);
    return RlamchZ__Float128();
}
