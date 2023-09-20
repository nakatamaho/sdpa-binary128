/*
 * Copyright (c) 2008-2023
 *	Nakata, Maho
 * 	All rights reserved.
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

#ifndef _MPLAPACK__FLOAT128_H_
#define _MPLAPACK__FLOAT128_H_

#include "mplapack_config.h"

_Float128 Rlamch_dd(const char *cmach);
void Rsyev(const char *jobz, const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, _Float128 *w, _Float128 *work, mplapackint const lwork, mplapackint &info);
void Rsteqr(const char *compz, mplapackint const n, _Float128 *d, _Float128 *e, _Float128 *z, mplapackint const ldz, _Float128 *work, mplapackint &info);
void Rpotrf(const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, mplapackint &info);
void Rpotf2(const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, mplapackint &info);
void Rpotrf2(const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, mplapackint &info);
void Rlascl(const char *type, mplapackint const kl, mplapackint const ku, _Float128 const cfrom, _Float128 const cto, mplapackint const m, mplapackint const n, _Float128 *a, mplapackint const lda, mplapackint &info);
void Rlascl2(mplapackint const m, mplapackint const n, _Float128 *d, _Float128 *x, mplapackint const ldx);
void Rsytrd(const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, _Float128 *d, _Float128 *e, _Float128 *tau, _Float128 *work, mplapackint const lwork, mplapackint &info);
void Rsytrd_2stage(const char *vect, const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, _Float128 *d, _Float128 *e, _Float128 *tau, _Float128 *hous2, mplapackint const lhous2, _Float128 *work, mplapackint const lwork, mplapackint &info);
void Rsytrd_sb2st(const char *stage1, const char *vect, const char *uplo, mplapackint const n, mplapackint const kd, _Float128 *ab, mplapackint const ldab, _Float128 *d, _Float128 *e, _Float128 *hous, mplapackint const lhous, _Float128 *work, mplapackint const lwork, mplapackint &info);
void Rsytrd_sy2sb(const char *uplo, mplapackint const n, mplapackint const kd, _Float128 *a, mplapackint const lda, _Float128 *ab, mplapackint const ldab, _Float128 *tau, _Float128 *work, mplapackint const lwork, mplapackint &info);
void Rsytd2(const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, _Float128 *d, _Float128 *e, _Float128 *tau, mplapackint &info);
void Rlae2(_Float128 const a, _Float128 const b, _Float128 const c, _Float128 &rt1, _Float128 &rt2);
void Rlasrt(const char *id, mplapackint const n, _Float128 *d, mplapackint &info);
void Rorgql(mplapackint const m, mplapackint const n, mplapackint const k, _Float128 *a, mplapackint const lda, _Float128 *tau, _Float128 *work, mplapackint const lwork, mplapackint &info);
void Rorgqr(mplapackint const m, mplapackint const n, mplapackint const k, _Float128 *a, mplapackint const lda, _Float128 *tau, _Float128 *work, mplapackint const lwork, mplapackint &info);
void Rlarfg(mplapackint const n, _Float128 &alpha, _Float128 *x, mplapackint const incx, _Float128 &tau);
void Rlarfgp(mplapackint const n, _Float128 &alpha, _Float128 *x, mplapackint const incx, _Float128 &tau);
void Rlassq(mplapackint const n, _Float128 *x, mplapackint const incx, _Float128 &scale, _Float128 &sumsq);
void Rorg2l(mplapackint const m, mplapackint const n, mplapackint const k, _Float128 *a, mplapackint const lda, _Float128 *tau, _Float128 *work, mplapackint &info);
void Rlarft(const char *direct, const char *storev, mplapackint const n, mplapackint const k, _Float128 *v, mplapackint const ldv, _Float128 *tau, _Float128 *t, mplapackint const ldt);
void Rlarfb(const char *side, const char *trans, const char *direct, const char *storev, mplapackint const m, mplapackint const n, mplapackint const k, _Float128 *v, mplapackint const ldv, _Float128 *t, mplapackint const ldt, _Float128 *c, mplapackint const ldc, _Float128 *work, mplapackint const ldwork);
void Rlarfb_gett(const char *ident, mplapackint const m, mplapackint const n, mplapackint const k, _Float128 *t, mplapackint const ldt, _Float128 *a, mplapackint const lda, _Float128 *b, mplapackint const ldb, _Float128 *work, mplapackint const ldwork);
void Rorg2r(mplapackint const m, mplapackint const n, mplapackint const k, _Float128 *a, mplapackint const lda, _Float128 *tau, _Float128 *work, mplapackint &info);
void Rlarf(const char *side, mplapackint const m, mplapackint const n, _Float128 *v, mplapackint const incv, _Float128 const tau, _Float128 *c, mplapackint const ldc, _Float128 *work);
void Rlarfb(const char *side, const char *trans, const char *direct, const char *storev, mplapackint const m, mplapackint const n, mplapackint const k, _Float128 *v, mplapackint const ldv, _Float128 *t, mplapackint const ldt, _Float128 *c, mplapackint const ldc, _Float128 *work, mplapackint const ldwork);
void Rlarfb_gett(const char *ident, mplapackint const m, mplapackint const n, mplapackint const k, _Float128 *t, mplapackint const ldt, _Float128 *a, mplapackint const lda, _Float128 *b, mplapackint const ldb, _Float128 *work, mplapackint const ldwork);
void Rlarfg(mplapackint const n, _Float128 &alpha, _Float128 *x, mplapackint const incx, _Float128 &tau);
void Rlarfgp(mplapackint const n, _Float128 &alpha, _Float128 *x, mplapackint const incx, _Float128 &tau);
void Rlarft(const char *direct, const char *storev, mplapackint const n, mplapackint const k, _Float128 *v, mplapackint const ldv, _Float128 *tau, _Float128 *t, mplapackint const ldt);
void Rlarfx(const char *side, mplapackint const m, mplapackint const n, _Float128 *v, _Float128 const tau, _Float128 *c, mplapackint const ldc, _Float128 *work);
void Rlarfy(const char *uplo, mplapackint const n, _Float128 *v, mplapackint const incv, _Float128 const tau, _Float128 *c, mplapackint const ldc, _Float128 *work);
void Rpotf2(const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, mplapackint &info);
void Rlaset(const char *uplo, mplapackint const m, mplapackint const n, _Float128 const alpha, _Float128 const beta, _Float128 *a, mplapackint const lda);
void Rlaev2(_Float128 const a, _Float128 const b, _Float128 const c, _Float128 &rt1, _Float128 &rt2, _Float128 &cs1, _Float128 &sn1);
void Rlasr(const char *side, const char *pivot, const char *direct, mplapackint const m, mplapackint const n, _Float128 *c, _Float128 *s, _Float128 *a, mplapackint const lda);
void Rlasrt(const char *id, mplapackint const n, _Float128 *d, mplapackint &info);
void Rlartg(_Float128 const f, _Float128 const g, _Float128 &cs, _Float128 &sn, _Float128 &r);
void Rlartgp(_Float128 const f, _Float128 const g, _Float128 &cs, _Float128 &sn, _Float128 &r);
void Rlartgs(_Float128 const x, _Float128 const y, _Float128 const sigma, _Float128 &cs, _Float128 &sn);
void Rlatrd(const char *uplo, mplapackint const n, mplapackint const nb, _Float128 *a, mplapackint const lda, _Float128 *e, _Float128 *tau, _Float128 *w, mplapackint const ldw);
void Rsterf(mplapackint const n, _Float128 *d, _Float128 *e, mplapackint &info);
void Rorgtr(const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, _Float128 *tau, _Float128 *work, mplapackint const lwork, mplapackint &info);
mplapackint iMparmq_dd(mplapackint const ispec, const char *name, const char *opts, mplapackint const n, mplapackint const ilo, mplapackint const ihi, mplapackint const lwork);
mplapackint iMieeeck_dd(mplapackint const &ispec, _Float128 const &zero, _Float128 const &one);
bool Rlaisnan(_Float128 const din1, _Float128 const din2);
bool Risnan(_Float128 const din);
mplapackint iMlaenv_dd(mplapackint ispec, const char *name, const char *opts, mplapackint n1, mplapackint n2, mplapackint n3, mplapackint n4);
_Float128 Rlanst(const char *norm, mplapackint const n, _Float128 *d, _Float128 *e);
_Float128 Rlapy2(_Float128 const x, _Float128 const y);
mplapackint iMladlr(mplapackint const m, mplapackint const n, _Float128 *a, mplapackint const lda);
mplapackint iMladlc(mplapackint const m, mplapackint const n, _Float128 *a, mplapackint const lda);
_Float128 Rlansy(const char *norm, const char *uplo, mplapackint const n, _Float128 *a, mplapackint const lda, _Float128 *work);
void Rcombssq(_Float128 *v1, _Float128 *v2);

#endif
