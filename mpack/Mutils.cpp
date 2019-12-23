/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Nakata, Maho
 * 
 * $Id: Mutils.cpp,v 1.7 2009/09/16 08:32:46 nakatamaho Exp $ 
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

__float128
mpf_approx_log2(__float128 x)
{
  return log2q(x);
}

__float128
mpf_approx_log(__float128 x)
{
    return logq(x);
}

__float128
mpf_approx_log10(__float128 x)
{
    return log10q(x);
}

__float128
mpf_approx_pow(__float128 x, __float128 y)
{
    return powq(x, y);
}

__float128
mpf_approx_cos(__float128 x)
{
    return cosq(x);
}

__float128
mpf_approx_sin(__float128 x)
{
    return sinq(x);
}

__float128
mpf_approx_exp(__float128 x)
{
    return expq(x);
}

__float128
mpf_approx_pi()
{
    __float128 mtemp1;
    mtemp1 = M_PIq;
    return mtemp1;
}
