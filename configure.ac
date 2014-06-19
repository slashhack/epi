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

AC_PROG_CC_STDC
AX_CXX_COMPILE_STDCXX_11

AM_PATH_PYTHON([3.0])

#ref https://llvm.org/viewvc/llvm-project/llvm/trunk/autoconf/configure.ac?diff_format=h&view=markup&sortby=log
#add compile options
#add profile-guided optimization

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([
        Makefile
        include/Makefile
        src/Makefile
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

# Configure options: --enable-optimize[=no].
AC_ARG_ENABLE([optimize],
        [AS_HELP_STRING([--enable-optimize],
        [enable optimize code (default is no)])],
        [optimize="$withval"], [optimize=no])

# Configure options: --enable-profile[=no].
AC_ARG_ENABLE([profile],
        [AS_HELP_STRING([--enable-profile],
        [enable profile code (default is no)])],
        [profile="$withval"], [profile=no])

        
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
