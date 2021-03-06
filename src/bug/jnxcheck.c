/*
 * =====================================================================================
 *
 *       Filename:  jnxcheck.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/16/14 08:17:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jonesax (jonesax@hush.com), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "jnxcheck.h"
#include <execinfo.h>
#include <stdio.h>
void jnxcheck_backtrace() {
  void *array[MAXSTACKFRAMES];
  size_t size;
  jnx_char **strings;
  jnx_size i;
  size = backtrace (array, MAXSTACKFRAMES);
  strings = backtrace_symbols (array, size);
  JNX_LOG(DEFAULT_CONTEXT,"Obtained %zd stack frames.", size);
  for (i = 0; i < size; i++)
    JNX_LOG(DEFAULT_CONTEXT,"%s", strings[i]);
  free (strings);
}
