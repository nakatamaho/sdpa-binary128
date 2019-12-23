/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Nakata, Maho
 * 
 * $Id: mlapack___float128.h,v 1.6 2009/09/22 20:27:18 nakatamaho Exp $ 
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

/* this is a subset of mpack for SDPA-GMP only */
/* http://mplapack.sourceforge.net/ */

/* mlapack prototypes */
void Rsteqr(const char *compz, mpackint n, __float128 * d, __float128 * e,
    __float128 * Z, mpackint ldz, __float128 * work, mpackint *info);
void
    Rsyev(const char *jobz, const char *uplo, mpackint n, __float128 * A,
    mpackint lda, __float128 * w, __float128 * work, mpackint *lwork, mpackint *info);
void Rpotrf(const char *uplo, mpackint n, __float128 * A, mpackint lda, mpackint *info);
mpackint iMlaenv___float128(mpackint ispec, const char *name, const char *opts, mpackint n1, mpackint n2,
    mpackint n3, mpackint n4);
__float128 Rlamch___float128(const char *cmach);
__float128 Rlansy(const char *norm, const char *uplo, mpackint n, __float128 * A,
    mpackint lda, __float128 * work);
void Rlascl(const char *type, mpackint kl, mpackint ku, __float128 cfrom, __float128 cto,
    mpackint m, mpackint n, __float128 * A, mpackint lda, mpackint *info);
void Rsytrd(const char *uplo, mpackint n, __float128 * A, mpackint lda, __float128 * d,
    __float128 * e, __float128 * tau, __float128 * work, mpackint lwork, mpackint *info);
void Rsytd2(const char *uplo, mpackint n, __float128 * A, mpackint lda, __float128 * d,
    __float128 * e, __float128 * tau, mpackint *info);
__float128 Rlanst(const char *norm, mpackint n, __float128 * d, __float128 * e);
void Rlae2(__float128 a, __float128 b, __float128 c, __float128 * rt1,
    __float128 * rt2);
__float128 Rlapy2(__float128 x, __float128 y);
void Rlasrt(const char *id, mpackint n, __float128 * d, mpackint *info);
void Rorgql(mpackint m, mpackint n, mpackint k, __float128 * A, mpackint lda, __float128 * tau,
    __float128 * work, mpackint lwork, mpackint *info);
void Rorgqr(mpackint m, mpackint n, mpackint k, __float128 * A, mpackint lda, __float128 * tau,
    __float128 * work, mpackint lwork, mpackint *info);
void Rlarfg(mpackint N, __float128 * alpha, __float128 * x, mpackint incx,
    __float128 * tau);
void Rlassq(mpackint n, __float128 * x, mpackint incx, __float128 * scale,
    __float128 * sumsq);
void Rorg2l(mpackint m, mpackint n, mpackint k, __float128 * A, mpackint lda, __float128 * tau,
    __float128 * work, mpackint *info);
void Rlarft(const char *direct, const char *storev, mpackint n, mpackint k,
    __float128 * v, mpackint ldv, __float128 * tau, __float128 * t, mpackint ldt);
void Rlarfb(const char *side, const char *trans, const char *direct,
    const char *storev, mpackint m, mpackint n, mpackint k, __float128 * V, mpackint ldv,
    __float128 * T, mpackint ldt, __float128 * C, mpackint ldc, __float128 * work,
    mpackint ldwork);
void Rorg2r(mpackint m, mpackint n, mpackint k, __float128 * A, mpackint lda, __float128 * tau,
    __float128 * work, mpackint *info);
void Rlarf(const char *side, mpackint m, mpackint n, __float128 * v, mpackint incv,
    __float128 tau, __float128 * C, mpackint ldc, __float128 * work);
void Rpotf2(const char *uplo, mpackint n, __float128 * A, mpackint lda, mpackint *info);
void Rlaset(const char *uplo, mpackint m, mpackint n, __float128 alpha, __float128 beta,
    __float128 * A, mpackint lda);
void Rlaev2(__float128 a, __float128 b, __float128 c, __float128 * rt1,
    __float128 * rt2, __float128 * cs1, __float128 * sn1);
void Rlasr(const char *side, const char *pivot, const char *direct, mpackint m,
    mpackint n, __float128 * c, __float128 * s, __float128 * A, mpackint lda);
void Rlartg(__float128 f, __float128 g, __float128 * cs, __float128 * sn,
    __float128 * r);
void Rlatrd(const char *uplo, mpackint n, mpackint nb, __float128 * A, mpackint lda, __float128 * e, __float128 * tau, __float128 * w, mpackint ldw);
void Rsterf(mpackint n, __float128 * d, __float128 * e, mpackint *info);
void Rorgtr(const char *uplo, mpackint n, __float128 * a, mpackint lda, __float128 * tau,
    __float128 * work, mpackint lwork, mpackint *info);
