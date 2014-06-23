#ifndef INCLUDE_UTIL_H
#define INCLUDE_UTIL_H

#include <assert.h>
#include <time.h>

inline void tp_add(struct timespec* from, struct timespec* to,
                   struct timespec* result) {
  result->tv_sec = from->tv_sec + to->tv_sec;
  result->tv_nsec = from->tv_nsec + to->tv_nsec;
  if (result->tv_nsec > 1000000000) {
    ++result->tv_sec;
    result->tv_nsec -= 1000000000;
  }
  assert((1000000000 > result->tv_nsec) && (0 <= result->tv_sec));
}

inline void tp_sub(struct timespec* from, struct timespec* to,
                   struct timespec* result) {
  result->tv_sec = from->tv_sec - to->tv_sec;
  result->tv_nsec = from->tv_nsec - to->tv_nsec;
  if (result->tv_nsec < 0) {
    --result->tv_sec;
    result->tv_nsec += 1000000000;
  }
  assert((1000000000 > result->tv_nsec) && (0 <= result->tv_sec));
}

inline float tp_to_sec(struct timespec* tp) {
  float result = (float) (tp->tv_sec);
  result += (float) (tp->tv_nsec) * 1E-9f;
  return result;
}

inline float tp_get_sec(clockid_t clock_id, struct timespec *tp) {
  struct timespec now;
  assert(0 == clock_gettime(clock_id, &now));

  struct timespec delta;
  tp_sub(&now, tp, &delta);

  return tp_to_sec(&delta);
}

#endif
