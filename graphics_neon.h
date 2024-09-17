/* -*- C++ -*-
 * 
 *  graphics_neon.h - graphics routines using X86 NEON cpu functionality
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

#ifndef __GRAPHICS_NEON_H__
#define __GRAPHICS_NEON_H__

#if ONS_ARM_NEON_AVAILIBLE
namespace ons_gfx {

//void imageFilterMean_NEON(uint8_t *src1, uint8_t *src2, uint8_t *dst, int length);
//void imageFilterAddTo_NEON(uint8_t *dst, uint8_t *src, int length);
//void imageFilterSubFrom_NEON(uint8_t *dst, uint8_t *src, int length);
//void imageFilterBlend_NEON(uint32_t *dst_buffer, uint32_t *src_buffer, uint8_t *alphap, int alpha, int length);
//void imageFilterEffectBlend_NEON(uint32_t *dst_buffer, uint32_t *src1_buffer, uint32_t *src2_buffer, uint32_t mask2, int length);
//void imageFilterEffectMaskBlend_NEON(uint32_t *dst_buffer, uint32_t *src1_buffer, uint32_t *src2_buffer, uint32_t *mask_buffer, uint32_t is_crossfade, uint32_t mask_value, int length);

}
#endif //ONS_ARM_NEON_AVAILIBLE

#endif // __GRAPHICS_NEON_H__
