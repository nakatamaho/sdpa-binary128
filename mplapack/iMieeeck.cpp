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

mplapackint iMieeeck__Float128(mplapackint const &ispec, _Float128 const &zero, _Float128 const &one) {
    mplapackint return_value = 0;
    return_value = 1;
    //
    _Float128 posinf = one / zero;
    if (posinf <= one) {
        return_value = 0;
        return return_value;
    }
    //
    _Float128 neginf = -one / zero;
    if (neginf >= zero) {
        return_value = 0;
        return return_value;
    }
    //
    _Float128 negzro = one / (neginf + one);
    if (negzro != zero) {
        return_value = 0;
        return return_value;
    }
    //
    neginf = one / negzro;
    if (neginf >= zero) {
        return_value = 0;
        return return_value;
    }
    //
    _Float128 newzro = negzro + zero;
    if (newzro != zero) {
        return_value = 0;
        return return_value;
    }
    //
    posinf = one / newzro;
    if (posinf <= one) {
        return_value = 0;
        return return_value;
    }
    //
    neginf = neginf * posinf;
    if (neginf >= zero) {
        return_value = 0;
        return return_value;
    }
    //
    posinf = posinf * posinf;
    if (posinf <= one) {
        return_value = 0;
        return return_value;
    }
    //
    //     Return if we were only asked to check infinity arithmetic
    //
    if (ispec == 0) {
        return return_value;
    }
    //
    _Float128 nan1 = posinf + neginf;
    //
    _Float128 nan2 = posinf / neginf;
    //
    _Float128 nan3 = posinf / posinf;
    //
    _Float128 nan4 = posinf * zero;
    //
    _Float128 nan5 = neginf * negzro;
    //
    _Float128 nan6 = nan5 * zero;
    //
    if (nan1 == nan1) {
        return_value = 0;
        return return_value;
    }
    //
    if (nan2 == nan2) {
        return_value = 0;
        return return_value;
    }
    //
    if (nan3 == nan3) {
        return_value = 0;
        return return_value;
    }
    //
    if (nan4 == nan4) {
        return_value = 0;
        return return_value;
    }
    //
    if (nan5 == nan5) {
        return_value = 0;
        return return_value;
    }
    //
    if (nan6 == nan6) {
        return_value = 0;
        return return_value;
    }
    //
    return return_value;
}
