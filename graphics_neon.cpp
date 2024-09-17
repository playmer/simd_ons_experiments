/* -*- C++ -*-
 * 
 *  graphics_neon.cpp - graphics routines using ARN NEON cpu functionality
 *
 *  Copyright (c) 2009-2011 "Uncle" Mion Sonozaki
 *
 *  UncleMion@gmail.com
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, see <http://www.gnu.org/licenses/>
 *  or write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

// Based upon routines provided by Roto

#if ONS_ARM_NEON_AVAILIBLE

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "graphics_sum.h"
#include "graphics_blend.h"

namespace ons_gfx {

//int imageFilterMean_NEON(uint8_t *src1, uint8_t *src2, uint8_t *dst, int length)
//{
//    return 0;
//}
//
//
//int imageFilterAddTo_NEON(uint8_t *dst, uint8_t *src, int length)
//{
//    return 0;
//}
//
//
//void imageFilterSubFrom_NEON(uint8_t *dst, uint8_t *src, int length)
//{
//}
//
//static inline __m128i alphaBlendCore_NEON(__m128i src1, __m128i src2, __m128i d_a)
//{
//}
//
//int imageFilterBlend_NEON(uint32_t *dst_buffer, uint32_t *src_buffer, uint8_t *alphap, int alpha, int length)
//{
//}
//
//int imageFilterEffectBlend_NEON(uint32_t *dst_buffer, uint32_t *src1_buffer, uint32_t *src2_buffer, uint32_t mask2, int length)
//{
//}
//
//int imageFilterEffectMaskBlend_NEON(uint32_t *dst_buffer, uint32_t *src1_buffer, uint32_t *src2_buffer, uint32_t *mask_buffer, uint32_t overflow_mask, uint32_t mask_value, int length)
//{
//}

}//namespace ons_gfx

#endif //ONS_ARM_NEON_AVAILIBLE
