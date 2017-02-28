/*
 * Copyright(C) 2016 Pedro H. Penna <pedrohenriquepenna@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define PAGE_SIZE 4096

/**
 * @brief Safe malloc().
 * 
 * @param n Number of bytes to allocate.
 * 
 * @returns A pointer to the allocated memory block.
 */
void *smalloc(size_t n)
{
	void *p;
	
	assert(posix_memalign(&p, PAGE_SIZE, n) == 0);
	
	return (p);
}

/**
 * @brief Prints and error message and exits.
 * 
 * @param msg Error message.
 */
void error(const char *msg)
{
	fprintf(stderr, "error: %s\n", msg);
	exit(EXIT_FAILURE);
}
