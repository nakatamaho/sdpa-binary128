/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Nakata, Maho
 * 
 * $Id: Rlamch.cpp,v 1.7 2009/09/18 23:01:08 nakatamaho Exp $ 
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

#include <mblas___float128.h>
#include <mlapack___float128.h>

__float128 RlamchE___float128(void)
{
    return FLT128_EPSILON;
}

//"S" denots we always calculate `safe minimum, such that 1/sfmin does not overflow'.
//cf.http://www.netlib.org/blas/dlamch.f
__float128 RlamchS___float128(void)
{
    //IEEE 754 2008 binary128: emin = -16382
    //2^{-16382} = 3.36210314311209350626267781732175260e-4932Q
    return FLT128_MIN;

    static __float128 eps;
    static int called = 0;
    if (called)
	return eps;
    eps = 1.0;
//We all know double is the IEEE 754 2008 binary128 format has 113bit significant digits 
    for (int i = 0; i < 16383; i++) {
	eps = eps / 2.0Q;
    }
    called = 1;
}

//"B" base  = base of the machine
//cf.http://www.netlib.org/blas/dlamch.f
__float128 RlamchB___float128(void)
{
    __float128 two;
    two = 2.0;
    return two;
}

//"P" prec = eps*base
//cf.http://www.netlib.org/blas/dlamch.f
__float128 RlamchP___float128(void)
{
    __float128 base, eps, prec;

    base = RlamchB___float128();
    eps = RlamchE___float128();
    prec = eps * base;
    return prec;
}

//"N" t = number of digits in mantissa
//cf.http://www.netlib.org/blas/dlamch.f
__float128 RlamchN___float128(void)
{
    return (__float128) FLT128_MANT_DIG;	//113
}

//"R" rnd   = 1.0 when rounding occurs in addition, 0.0 otherwise
//cf.http://www.netlib.org/blas/dlamch.f
__float128 RlamchR___float128(void)
{
    __float128 mtmp;
    mtmp = 1.0;
    return mtmp;
}

//"M"
//cf.http://www.netlib.org/blas/dlamch.f
__float128 RlamchM___float128(void)
{
//the exponent of IEEE 754 2008 binary64 is -16382.
//then -16382 + 1 = -16381
    return FLT128_MIN_EXP;
}

//"U"
//cf.http://www.netlib.org/blas/dlamch.f
__float128 RlamchU___float128(void)
{
    return FLT128_MIN;

//2^{-16382+1} minimum exponent
    static double eps;
    static int called = 0;
    if (called)
	return eps;
    eps = 1.0;
//We all know double is the IEEE 754 2008 binary128 format has 113bit significant digits 
    for (int i = 0; i < 16382; i++) {
	eps = eps / 2.0;
    }
    called = 1;
    return eps;

}

//"L"
//cf.http://www.netlib.org/blas/dlamch.f
__float128 RlamchL___float128(void)
{
//+16383 in IEEE 754 2008 binary128
//then 16383 + 1 = 16384
    return FLT128_MAX_EXP;
}

//"O"
//cf.http://www.netlib.org/blas/dlamch.f
__float128 RlamchO___float128(void)
{
// 1.18973149535723176508575932662800702e4932Q in IEEE 754 2008 binary128.
    return FLT128_MAX;
}

//"Z" :dummy
//cf.http://www.netlib.org/blas/dlamch.f
__float128 RlamchZ___float128(void)
{
    __float128 mtemp = 0.0;
    return mtemp;
}

__float128 Rlamch___float128(const char *cmach)
{
    if (Mlsame___float128(cmach, "E"))
	return RlamchE___float128();
    if (Mlsame___float128(cmach, "S"))
	return RlamchS___float128();
    if (Mlsame___float128(cmach, "B"))
	return RlamchB___float128();
    if (Mlsame___float128(cmach, "P"))
	return RlamchP___float128();
    if (Mlsame___float128(cmach, "N"))
	return RlamchN___float128();
    if (Mlsame___float128(cmach, "R"))
	return RlamchR___float128();
    if (Mlsame___float128(cmach, "M"))
	return RlamchM___float128();
    if (Mlsame___float128(cmach, "U"))
	return RlamchU___float128();
    if (Mlsame___float128(cmach, "L"))
	return RlamchL___float128();
    if (Mlsame___float128(cmach, "O"))
	return RlamchO___float128();

    Mxerbla___float128("Rlamch", 1);
    return RlamchZ___float128();
}
