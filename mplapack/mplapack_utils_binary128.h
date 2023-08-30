/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2009 by Nakata, Maho
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

#ifndef _MUTILS_DD_H_
#define _MUTILS_DD_H_


#define mpack_max(a, b) ((a) > (b) ? (a) : (b))
#define mpack_min(a, b) ((a) < (b) ? (a) : (b))

//inline __float128 abs (__float128 a)
//{
//    return fabsq(a);
//}

__float128 Msign(__float128 a, __float128 b);
double cast2double(__float128 a);
int M2int(__float128 a);
//void mpf_pow(mpf_t ans, mpf_t x, mpf_t y);
__float128 mpf_approx_log(__float128 x);
__float128 mpf_approx_log2(__float128 x);
__float128 mpf_approx_log10(__float128 x);
__float128 mpf_approx_pow(__float128 x, __float128 y);
__float128 mpf_approx_cos(__float128 x);
__float128 mpf_approx_sin(__float128 x);
__float128 mpf_approx_exp(__float128 x);
__float128 mpf_approx_pi();

//implementation of sign transfer function.
inline __float128 Msign(__float128 a, __float128 b)
{
  __float128 mtmp;
  mtmp=abs(a);
  if (b<0.0) {
    mtmp=-mtmp;
  }
  return mtmp;
}

inline double
cast2double(__float128 a)
{
    return (double)a;
}

inline int
M2int(__float128 a)
{
    int i;
    __float128 tmp;
    a = a + 0.5;
    tmp = floorq(a);
    i = (int)tmp;
    return i;
}

#endif
