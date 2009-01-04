/*
 * libewf offset table
 *
 * Copyright (c) 2006, Joachim Metz <forensics@hoffmannbv.nl>,
 * Hoffmann Investigations. All rights reserved.
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of the creator, related organisations, nor the names of
 *   its contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * - All advertising materials mentioning features or use of this software
 *   must acknowledge the contribution by people stated in the acknowledgements.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER, COMPANY AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _LIBEWF_OFFSET_TABLE_H
#define _LIBEWF_OFFSET_TABLE_H

#include <inttypes.h>

#include "ewf_table.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LIBEWF_OFFSET_TABLE libewf_offset_table_t
#define LIBEWF_OFFSET_TABLE_SIZE sizeof( LIBEWF_OFFSET_TABLE )
#define LIBEWF_OFFSET_TABLE_FILE_DESCRIPTOR_SIZE sizeof( int )
#define LIBEWF_OFFSET_TABLE_COMPRESSED_SIZE sizeof( uint8_t )
#define LIBEWF_OFFSET_TABLE_OFFSET_SIZE sizeof( uint64_t )
#define LIBEWF_OFFSET_TABLE_SIZE_SIZE sizeof( uint64_t )

typedef struct libewf_offset_table libewf_offset_table_t;

struct libewf_offset_table
{
	/* Stores the amount of chunks in the table
	 * There is an offset per chunk in the table
	 */
	uint64_t amount;

	/* The last chunk that was defined
	 */
	uint64_t last;

	/* Dynamic array (same size as offset) of file descriptor into the
	 * correct file, must already be opened by initialiser
	 */
	int *file_descriptor;

	/* Dynamic array (same size as offset) of boolean that definines
	 * if the chunk is compressed
	 */
	uint8_t *compressed;

	/* Dynamic array of offsets
	 */
	uint64_t *offset;

	/* Dynamic array of chunk sizes
	 */
	uint64_t *size;
};

LIBEWF_OFFSET_TABLE *libewf_offset_table_alloc( uint32_t size );
LIBEWF_OFFSET_TABLE *libewf_offset_table_realloc( LIBEWF_OFFSET_TABLE *offset_table, uint32_t size );
void libewf_offset_table_free( LIBEWF_OFFSET_TABLE *offset_table );
LIBEWF_OFFSET_TABLE *libewf_offset_table_set_values( LIBEWF_OFFSET_TABLE *offset_table, uint32_t chunk, int file_descriptor, uint8_t compressed, uint64_t offset, uint64_t size );

#ifdef __cplusplus
}
#endif

#endif
