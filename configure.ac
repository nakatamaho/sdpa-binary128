dnl
dnl Configure for SDPA-BINARY128 7.1.3
dnl

AC_INIT(sdpa-binary128, 7.1.3)
AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE([subdir-objects])
AC_PROG_CC
AC_PROG_CXX
AC_CANONICAL_HOST
AC_OPENMP
AC_LANG([C++])
AC_OPENMP

highest_abs_top_srcdir=`cd "$srcdir" && pwd`

AC_ARG_WITH(system-spooles,
[  --with-system-spooles      Use spooles already on system],
WITH_SYSTEM_SPOOLES=$withval, WITH_SYSTEM_SPOOLES=no)
AM_CONDITIONAL(BUILD_SPOOLES, test x$WITH_SYSTEM_SPOOLES = xno)

AC_ARG_WITH(spooles-includedir,
[  --with-spooles-includedir    Gives spooles include dir you use(e.g., /usr/local/include/spooles).],
SPOOLES_INCLUDEDIR=$withval
)

AC_ARG_WITH(spooles-libdir,
[  --with-spooles-libdir    Gives spooles lib dir you use(e.g., /usr/local/lib).],
SPOOLES_LIBDIR=$withval
)

AC_ARG_WITH(system-mplapack,
[  --with-system-mplapack      Use mplapack already on system],
WITH_SYSTEM_MPLAPACK=$withval, WITH_SYSTEM_MPLAPACK=no)
AM_CONDITIONAL(BUILD_MPLAPACK, test x$WITH_SYSTEM_MPLAPACK = xno)

AC_ARG_WITH(mplapack-includedir,
[  --with-mplapack-includedir    Gives mplapack include dir you use(e.g., /usr/local/include).],
MPLAPACK_INCLUDEDIR=$withval
)

AC_ARG_WITH(mplapack-libdir,
[  --with-mplapack-libdir    Gives mplapack lib dir you use(e.g., /usr/local/lib).],
MPLAPACK_LIBDIR=$withval
)

dnl spooles requires -lm when linking.
LIBS="-lm"

IS_LINUX=0
case "$host" in
    *linux*)
        IS_LINUX=1
        ;;
    *)
esac
AM_CONDITIONAL(IS_LINUX, test x$IS_LINUX = x1)

IS_MINGW=0
case "$host" in
        *-mingw32*) # mingw
          IS_MINGW=1
        ;;
        *)
esac
AM_CONDITIONAL(IS_MINGW, test x$IS_MINGW = x1)

IS_MACOS=0
case "$host" in
         *apple-darwin*) # MacOSX
          IS_MACOS=1
        ;;
        *)
esac
AM_CONDITIONAL(IS_MACOS, test x$IS_MACOS = x1)

dnl How thread we link thread library esp. needed for spooles.
case "$host" in
        *-*-linux*|*-*-uclinux*)
            pthread_cflags="-D_REENTRANT"
            pthread_lib="-lpthread"
            ;;
        *-*-freebsd*|*-*-dragonfly*)
            pthread_cflags=""
            pthread_lib="-pthread"
        ;;
esac
LIBS="$LIBS $pthread_lib"
CXXFLAGS="$CXXFLAGS $pthread_cflags"
AC_SUBST(pthread_lib)

CFLAGS="$CFLAGS -O2 -funroll-all-loops"
CXXFLAGS="$CXXFLAGS -O2 -funroll-all-loops"
AC_SUBST(CFLAGS)
AC_SUBST(CXXFLAGS)

dnl some dummy settings
if test x$SPOOLES_INCLUDEDIR = x; then
SPOOLES_INCLUDEDIR="."
fi
if test x$SPOOLES_LIBDIR = x; then
SPOOLES_LIBDIR="."
fi

dnl

if test x$WITH_SYSTEM_SPOOLES != xno; then
  dnl Check for SPOOLES include and library files
  HAVE_SPOOLES_HEADER=""
  HAVE_SPOOLES=""
  save_CPPFLAGS="$CPPFLAGS"
  CPPFLAGS="$CPPFLAGS -I$SPOOLES_INCLUDEDIR"
  AC_CHECK_HEADER(SPOOLES.h, HAVE_SPOOLES_HEADER=yes)
  CPPFLAGS=$save_CPPFLAGS

  if test x$HAVE_SPOOLES_HEADER = xyes; then
    save_LDFLAGS="$LDFLAGS"
    LDFLAGS="$LDFLAGS -L$SPOOLES_LIBDIR"
    AC_CHECK_LIB(spooles, InpMtx_init, [SPOOLES_LIB="-lspooles"; HAVE_SPOOLES=yes])
    LDFLAGS=$save_LDFLAGS
  fi

  if test x$HAVE_SPOOLES != xyes; then
    echo "Please install SPOOLES"
    echo "SPOOLES http://www.netlib.org/linalg/spooles/spooles.2.2.html"
    AC_MSG_ERROR([No SPOOLES found])
  fi
else
SPOOLES_LIBDIR=$highest_abs_top_srcdir/external/i/SPOOLES/lib
SPOOLES_INCLUDEDIR=$highest_abs_top_srcdir/external/spooles/work/internal #just too messy
fi
AC_SUBST(SPOOLES_LIBDIR)
AC_SUBST(SPOOLES_INCLUDEDIR)

# For unknown reason, the f128 suffix doesn't work in g++-9, but it does in gcc-9.
AC_MSG_CHECKING([whether _Float128 is supported])
AC_LINK_IFELSE([
   AC_LANG_SOURCE([[
   #include <stdio.h>
   #include <math.h>
   #include <stdlib.h>
   int main() {
       _Float128 a, b, c; b = 1.0q; c=3.0q; a = b / c;
       char buf[1024];
       strfromf128(buf, sizeof(buf), "%.40g", a);
       printf("fp128 %s\n",buf);
   }
  ]])
], [have__Float128=yes], [have__Float128=no])

if test x"$have__Float128" = x"yes"; then
     AC_MSG_RESULT([_Float128 is supported])
else
     AC_MSG_RESULT([_Float128 is not supported])
fi

if test x"$have__Float128" = x"yes"; then
    AC_COMPILE_IFELSE([
    AC_LANG_SOURCE([[
        #include <stdio.h>
        #include <math.h>
        #include <stdlib.h>
        int main() {
           long double *x;
           _Float128 *y = x;
        }
    ]])
    ], [_Float128islongdouble=yes], [_Float128islongdouble=no])

    if test "$_Float128islongdouble" = "yes"; then
         AC_MSG_RESULT([_Float128 is long double])
    else
         AC_MSG_RESULT([_Float128 is not long double])
    fi
fi

if test x"$have__Float128" = x"no"; then
    AC_COMPILE_IFELSE([
    AC_LANG_SOURCE([[
       #include <stdio.h>
       #include <limits>
       int main(){
       #if __LDBL_MANT_DIG__  >= 113
          printf("%d\n",__LDBL_MANT_DIG__);
       #else
       #error
       #endif
    }
    ]])
    ], [longdoubleisbinary128=yes], [longdoubleisbinary128=no])

    if test "$longdoubleisbinary128" = "yes"; then
        AC_MSG_RESULT([long double is binary128])
    else
        AC_MSG_RESULT([long double is not binary128])
    fi
fi

save_LIBS="$LIBS"
LIBS="-lquadmath $LIBS"
AC_LINK_IFELSE([
    AC_LANG_SOURCE([[
        #include <quadmath.h>
        #include <stdio.h>
        int main(){
            char buf[1024];
            __float128 a, b, c; b = 1.0q; c= 3.0q; a = b / c;
            quadmath_snprintf(buf,128,"%.40Qf\n",a);
            printf("%s",buf);
       }
   ]])
], [have___float128=yes], [have___float128=no])
LIBS="$save_LIBS"
if test x"$have___float128" = x"yes"; then
     AC_MSG_RESULT([__float128 is supported])
else
     AC_MSG_RESULT([__float128 is not supported])
fi

if test x"$have__Float128" = x"yes"; then
    want_libquadmath=no
else
    want_libquadmath=yes
fi

if test "$have___float128" = "yes" && test x"$want_libquadmath" = x"yes" ; then
    AC_MSG_RESULT([_Float128 is supported via __float128 and libquadmath])
    sed 's/%%MPLAPACK_BINARY128%%/#define ___MPLAPACK_WANT_LIBQUADMATH___/g' mplapack/mplapack_utils__Float128.h.in > mplapack/mplapack_utils__Float128.h
    sed 's/%%MPLAPACK_BINARY128%%/#define ___MPLAPACK_WANT_LIBQUADMATH___/g' sdpa_tool.h.in > sdpa_tool.h
elif test "$have__Float128" = "yes" && test x"$_Float128islongdouble" = x"yes"; then
    AC_MSG_RESULT([_Float128 is supported via native libc and _Float128 and long double are the same])
    sed 's/%%MPLAPACK_BINARY128%%/#define ___MPLAPACK__FLOAT128_IS_LONGDOUBLE___/g' mplapack/mplapack_utils__Float128.h.in > mplapack/mplapack_utils__Float128.h
    sed 's/%%MPLAPACK_BINARY128%%/#define ___MPLAPACK__FLOAT128_IS_LONGDOUBLE___/g' sdpa_tool.h.in > sdpa_tool.h
elif test "$have__Float128" = "yes" && test x"$_Float128islongdouble" != x"yes"; then
     if test x"$have___float128" = x"yes" ; then
         AC_MSG_RESULT([_Float128 is supported via native libc and long double is not binary128, I have __float128 but I use it as _Float128 instead.])
     elif test x"$have___float128" = x"no" ; then
         AC_MSG_RESULT([_Float128 is supported via native libc and _Float128 is the only binary128 on this system, and long double is not binary128.])
     fi
     sed 's/%%MPLAPACK_BINARY128%%/#define ___MPLAPACK__FLOAT128_ONLY___/g' mplapack/mplapack_utils__Float128.h.in > mplapack/mplapack_utils__Float128.h
     sed 's/%%MPLAPACK_BINARY128%%/#define ___MPLAPACK__FLOAT128_ONLY___/g' sdpa_tool.h.in > sdpa_tool.h
elif test "$have__Float128" = "no" && test x"$longdoubleisbinary128" = x"yes"; then
    AC_MSG_RESULT([long double is binary128, but neither _Float128 nor __float128 are supported])
    sed 's/%%MPLAPACK_BINARY128%%/#define ___MPLAPACK_LONGDOUBLE_IS_BINARY128___/g' mplapack/mplapack_utils__Float128.h.in > mplapack/mplapack_utils__Float128.h
    sed 's/%%MPLAPACK_BINARY128%%/#define ___MPLAPACK_LONGDOUBLE_IS_BINARY128___/g' sdpa_tool.h.in > sdpa_tool.h
else
    AC_MSG_ERROR([binary128 is not supported on this system])
fi
AM_CONDITIONAL(ENABLE__FLOAT128, test x$enable__Float128 = xyes)
AM_CONDITIONAL(WANT_QUADMATH, test x$want_libquadmath = xyes)
AM_CONDITIONAL(IS__FLOAT128_LONGDOUBLE, test x$_Float128islongdouble = xyes)
AM_CONDITIONAL(IS_LONGDOUBLE_BINARY128, test x$longdoubleisbinary128 = xyes)

dnl Check for MPLAPACK include and library files
dnl some dummy settings
if test x$MPLAPACK_INCLUDEDIR = x; then
MPLAPACK_INCLUDEDIR="."
fi
if test x$MPLAPACK_LIBDIR = x; then
MPLAPACK_LIBDIR="."
fi

if test x$WITH_SYSTEM_MPLAPACK != xno; then
HAVE_MPLAPACK_HEADER=""
HAVE_MPLAPACK=""
save_CPPFLAGS="$CPPFLAGS"
CPPFLAGS="$CPPFLAGS -I$MPLAPACK_INCLUDEDIR"
AC_LANG_PUSH([C++])
AC_CHECK_HEADER(mpblas__Float128.h, HAVE_MPLAPACK_HEADER=yes)
CPPFLAGS=$save_CPPFLAGS

if test x$HAVE_MPLAPACK_HEADER = xyes; then
  save_LDFLAGS="$LDFLAGS"
  LDFLAGS="$LDFLAGS -L$MPLAPACK_LIBDIR"
  LIBS="$LDFLAGS -L$MPLAPACK_LIBDIR -lmplapack__Float128 -lmpblas__Float128_opt"
 # AC_CHECK_FUNC(Rsyev, [HAVE_MPLAPACK=yes])
  HAVE_MPLAPACK=yes
  if test x$IS_LINUX = x1; then
    LDFLAGS="$save_LDFLAGS -Wl,--rpath=$MPLAPACK_LIBDIR"
  fi
fi

if test x$HAVE_MPLAPACK = xyes; then
  echo "System MPLAPACK found"
fi
if test x$HAVE_MPLAPACK != xyes; then
  echo "Please install MPLAPACK (MPBLAS/MPLAPACK)"
  echo "https://github.com/nakatamaho/mplapack/"
  AC_MSG_ERROR([No MPLAPACK found])
fi
else
MPLAPACK_LIBDIR=$highest_abs_top_srcdir/mplapack
MPLAPACK_INCLUDEDIR=$highest_abs_top_srcdir/mplapack
fi
AM_CONDITIONAL(SYSTEM_MPLAPACK, test x$with_system_mplapack = xyes)
AC_SUBST(MPLAPACK_LIBDIR)
AC_SUBST(MPLAPACK_INCLUDEDIR)

AC_CONFIG_FILES([
external/Makefile
external/spooles/Makefile
])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
