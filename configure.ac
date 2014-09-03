#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([epi],[0.1],[slashhack@slashhack.org],[],[https://www.github.com/slashhack])

AC_CONFIG_AUX_DIR([autoconf])
AM_INIT_AUTOMAKE([-Wall -Werror])
AM_SILENT_RULES([yes])

LT_PREREQ([2.4])
LT_INIT([dlopen])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

# AC_PROG_CC_STDC
# AX_CXX_COMPILE_STDCXX_11

AM_PATH_PYTHON([3.0])

#ref https://llvm.org/viewvc/llvm-project/llvm/trunk/autoconf/configure.ac?diff_format=h&view=markup&sortby=log
#add compile options
#add profile-guided optimization

# Checks for libraries.
AC_CHECK_LIB([dl], [dlopen])
AC_CHECK_LIB([rt], [clock_gettime])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for header files.
AC_CHECK_HEADERS([float.h inttypes.h limits.h stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE

# Checks for library functions.
AC_CHECK_FUNCS([clock_gettime])

AC_CONFIG_FILES([
        Makefile
        include/Makefile
        src/Makefile
        src/ch05/Makefile
        src/ch06/Makefile
        src/ch07/Makefile
        src/ch08/Makefile
        src/ch09/Makefile
        src/ch10/Makefile
        src/ch11/Makefile
        src/ch12/Makefile
        src/ch13/Makefile
        src/ch14/Makefile
        src/ch15/Makefile
        src/ch16/Makefile
        src/ch17/Makefile
        src/ch18/Makefile
        src/ch19/Makefile
        src/ch20/Makefile
        src/ch21/Makefile
        script/Makefile
        script/python/Makefile
        script/util/Makefile
        data/Makefile
        etc/Makefile
        ])

# Configure options: --enable-debug[=no].
AC_ARG_ENABLE([debug],
        [AS_HELP_STRING([--enable-debug],
        [enable debug code (default is no)])],
        [debug="$withval"], [debug=no])

# Configure options: --enable-release[=no].
AC_ARG_ENABLE([release],
        [AS_HELP_STRING([--enable-release],
        [enable release code (default is no)])],
        [release="$withval"], [release=no])

# Configure options: --enable-profile[=no].
AC_ARG_ENABLE([profile],
        [AS_HELP_STRING([--enable-profile],
        [enable profile code (default is no)])],
        [profile="$withval"], [profile=no])

GCC_COMMON_OPTION=""
GCC_COMMON_OPTION+=" -Wall -Wextra -Wformat=2 -Wstrict-aliasing=2 -Wcast-align "
GCC_COMMON_OPTION+=" -Wwrite-strings -Wconversion -Wfloat-equal -Wpointer-arith "
GCC_COMMON_OPTION+=" -Wswitch-enum -rdynamic "

#LIBS="-lrt -ldl"

#CFLAGS="$GCC_COMMON_OPTION"
#CXXFLAGS="$GCC_COMMON_OPTION"

# add libmudflap
# -g -fmudflap for compiler, -lmudflap for linker
# elf and dwarf information to debug build

# release : O3 native optimize
# default : -g O2 ..
# debug   : -g3 -O0 ...

if test $debug = yes ; then
    GCC_COMMON_OPTION+=" -g3 -O0 -ftrapv -fstack-protector "
    CFLAGS="$GCC_COMMON_OPTION"
    CXXFLAGS="$GCC_COMMON_OPTION -Weffc++"
else
    if test $release = yes ; then
        GCC_COMMON_OPTION+=" -g0 -O3 -march=native -mtune=native"
        CFLAGS="$GCC_COMMON_OPTION"
        CXXFLAGS="$GCC_COMMON_OPTION -Weffc++"
    else
        GCC_COMMON_OPTION+=" -g -O2 -ftrapv -fstack-protector -D_FORTIFY_SOURCE=2 "
        CFLAGS="$GCC_COMMON_OPTION"
        CXXFLAGS="$GCC_COMMON_OPTION -Weffc++"
    fi
fi
# if debug
#   ...
# else
#  if release
#     ...
#  else
#     ...
# done

# if profile
#   ...

#AC_SUBST(CFLAGS)
#AC_SUBST(CXXFLAGS)
#AC_SUBST(LDFLAGS)

# TODO
CFLAGS="-std=c99 $CFLAGS"
CXXFLAGS="-std=c++11 $CXXFLAGS"

AC_OUTPUT

echo "
     Prefix.........: $prefix
     Debug Build....: $debug
     Optimize Build.: $optimize
     Profile Build..: $profile
     C   Compiler...: $CC  $CFLAGS   $CPPFLAGS
     C++ Compiler...: $CXX $CXXFLAGS $CPPFLAGS
     Linker.........: $LD $LDFLAGS $LIBS 
"

