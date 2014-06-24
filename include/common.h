#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

#if defined __cplusplus
#define BEGIN_C_DECLS extern "C" {
#define END_C_DECLS }
#else
#define BEGIN_C_DECLS
#define END_C_DECLS
#endif

#include <assert.h>
#include <errno.h>
#include <signal.h>

#ifdef __cplusplus
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif
#endif

#include <stdint.h>
#include <inttypes.h>

#include <limits.h>
#include <float.h>

#ifdef __cplusplus
#define ALIGN(x,a)              __ALIGN_MASK(x,(typeof(x))(a)-1)
#else
#define ALIGN(x,a)              __ALIGN_MASK(x,(typeof(x))(a)-1
#endif
#define __ALIGN_MASK(x,mask)    (((x)+(mask))&~(mask))

#define likely(x)    __builtin_expect(!!(x), 1)
#define unlikely(x)  __builtin_expect(!!(x), 0)

#define RAISE_SIGTRAP   raise(SIGTRAP)



#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#endif
