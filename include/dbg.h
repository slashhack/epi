#ifndef INCLUDE_DBG_H
#define INCLUDE_DBG_H

#ifndef __PRETTY_FUNCTION__
#define __PRETTY_FUNCTION__ __func__
#endif

#define DBG(fmt, ...) \
    __dbg(fmt, __FILE__, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__);

#define DBG_BACKTRACE(fmt, ...) \
    __dbg_backtrace(fmt, __FILE__, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__);

#include <stdio.h>
#include <stdarg.h>
#include <execinfo.h>
#include <dlfcn.h>

inline void __dbg(const char * const fmt, const char * const file,
                  const char * const func, const int line, ...) {

  const char * const COLOR_NORMAL = "\033[0m";
  const char * const COLOR_RED = "\033[1;31m";
  const char * const COLOR_GREEN = "\033[1;32m";
  const char * const COLOR_YELLOW = "\033[1;33m";

  FILE * out = stdout;

  char format[4096];
  sprintf(format, "%s %s %s %s %s %04d %s: %s", COLOR_RED, file, COLOR_GREEN,
          func, COLOR_YELLOW, line, COLOR_NORMAL, fmt);
  va_list args;
  va_start(args, format);
  vfprintf(out, format, args);
  va_end(args);

  fflush(out);
}

#ifdef __cplusplus

#include <cxxabi.h>

inline void __dbg_backtrace(const char * const fmt, const char * const file,
                            const char * const func, const int line, ...) {

  const char * const COLOR_NORMAL = "\033[0m";
  const char * const COLOR_RED = "\033[1;31m";
  const char * const COLOR_GREEN = "\033[1;32m";
  const char * const COLOR_YELLOW = "\033[1;33m";

  FILE * out = stdout;

  using namespace abi;
  enum {
    MAX_DEPTH = 0xFF
  };

  void *trace[MAX_DEPTH];

  Dl_info dlinfo;

  int status;
  const char *symname;
  char *demangled;
  char **strings;

  int trace_size = backtrace(trace, MAX_DEPTH);
  strings = backtrace_symbols(trace, trace_size);

  fprintf(out, "%s %s %s %s %s %04d %s\n", COLOR_RED, file, COLOR_GREEN, func,
          COLOR_YELLOW, line, COLOR_NORMAL);
  fprintf(out, "\n\tBacktrace\n");

  for (int i = 0; i < trace_size; ++i) {
    if (dladdr(trace[i], &dlinfo)) {
      symname = dlinfo.dli_sname;

      demangled = __cxa_demangle(symname, NULL, 0, &status);
      if (status == 0 && demangled) {
        symname = demangled;
      }

      fprintf(out, "\t%s#%-2d %s%018p %sin %s%s%s at %s\n", COLOR_RED, i,
              COLOR_GREEN, dlinfo.dli_saddr, COLOR_NORMAL, COLOR_YELLOW,
              symname, COLOR_NORMAL, dlinfo.dli_fname);

      if (demangled) {
        free(demangled);
      }
    } else {
      fprintf(out, "\t%s#%-2d %s%018p %sin %s%s%s at %s\n", COLOR_RED, i,
              COLOR_GREEN, NULL, COLOR_NORMAL, COLOR_YELLOW, strings[i],
              COLOR_NORMAL, NULL);
    }

  }

  free(strings);

  fprintf(out, "\n\tMessage\n\t");

  va_list args;
  va_start(args, fmt);
  vfprintf(out, fmt, args);
  va_end(args);

  fflush(out);
}

#else

inline void __dbg_backtrace(const char * fmt, const char * file,
    const char *func, int line, ...) {

  const char * const COLOR_NORMAL = "\033[0m";
  const char * const COLOR_RED = "\033[1;31m";
  const char * const COLOR_GREEN = "\033[1;32m";
  const char * const COLOR_YELLOW = "\033[1;33m";

  FILE * out = stdout;

  using namespace abi;
  enum {
    MAX_DEPTH = 0xFF
    void *trace[MAX_DEPTH];

    Dl_info dlinfo;

    const char *symname;

    int trace_size = backtrace(trace, MAX_DEPTH);

    fprintf(out, "%s %s %s %s %s %04d %s\n", COLOR_RED, file, COLOR_GREEN, func,
        COLOR_YELLOW, line, COLOR_NORMAL);
    fprintf(out, "\n\tBacktrace\n");

    for (int i = 1; i < trace_size - 1; ++i) {
      if (!dladdr(trace[i], &dlinfo)) {
        continue;
      }

      symname = dlinfo.dli_sname;

      fprintf(out, "\t%s#%-2d %s%018p %sin %s%s%s\n", COLOR_RED, i,
          COLOR_GREEN, dlinfo.dli_saddr, COLOR_NORMAL, COLOR_YELLOW,
          symname, COLOR_NORMAL);

      if (demangled) {
        free(demangled);
      }
    }

    fprintf(out, "\n\tMessage\n\t");

    va_list args;
    va_start(args, fmt);
    vfprintf(out, fmt, args);
    va_end(args);

    fflush(out);
  }
}

#endif

#endif
