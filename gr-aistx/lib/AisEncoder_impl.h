/* -*- c++ -*- */
/* 
 * Copyright 2013 <+YOU OR YOUR COMPANY+>.
 * Copyright 2015 Harald Welte <hwelte@sysmocom.de>
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
 
#ifndef INCLUDED_AISTX_BUILD_FRAME_IMPL_H
#define INCLUDED_AISTX_BUILD_FRAME_IMPL_H

#include <AISTX/AisEncoder.h>

#define __VERSION 0.3

namespace gr {
  namespace AISTX {

    class AisEncoder_impl : public AisEncoder
    {
     private:
		bool d_enable_NRZI;

     public:
	AisEncoder_impl(bool enable_NRZI);
        ~AisEncoder_impl();

		void dump_buffer(const char *b, int buffer_size);
		char *int2bin(int a, char *buffer, int buf_size);
		int stuff (const char *in, char *out, int l_in);
		void pack (int orig_ascii, char *ret, int bits_per_byte);
		void nrz_to_nrzi(char *data, int length);
		void reverse_bit_order(char *data, int length);
		unsigned long unpack(char *buffer, int start, int length);
		void compute_crc(char *buffer, char *ret, unsigned int len);
		void byte_packing(char *input_frame, unsigned char *out_byte, unsigned int len);

      // Where all the action really happens
	void handle_msg(pmt::pmt_t pdu);
    };

  } // namespace AISTX
} // namespace gr

#endif /* INCLUDED_AISTX_BUILD_FRAME_IMPL_H */

