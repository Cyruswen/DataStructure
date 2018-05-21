#pragma once
#include <stddef.h>
#include <stdint.h>

uint64_t SDBMHash(const char* str);
uint64_t BKDRHash(const char* str);
