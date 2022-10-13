#pragma once
#ifndef _MRRAND_
#define _MRRAND_
#include <Windows.h>
#include <ctime>
#include <random>
class RDOM {
  std::mt19937* rxd;

 public:
  RDOM() { rxd = new std::mt19937(time(0)); }

  uintmax_t operator()(uintmax_t mod = 2147483648) {
    FILETIME t;
    GetSystemTimeAsFileTime(&t);
    return (((((uintmax_t)t.dwHighDateTime << 32ull) + t.dwLowDateTime) % mod) ^
            (*rxd)()) %
           mod;
  }
} rd;
#endif