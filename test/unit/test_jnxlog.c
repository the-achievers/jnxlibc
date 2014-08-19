/*
 * =====================================================================================
 *
 *       Filename:  test_jnxhash.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/27/13 16:20:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alex Jones (), alexsimonjones@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "jnxfile.h"
#include "jnxlog.h"
#include "jnxterm.h"
int main(int args, char **argv) {
  printf("Running test for jnxlog");


  jnx_term_printf_in_color(JNX_COL_GREEN, "  OK\n");
  return 0;
}
