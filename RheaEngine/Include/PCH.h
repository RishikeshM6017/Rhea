#pragma once

#include <stdio.h>
#include <assert.h>

#include <cstdlib>
#include <type_traits>
#include <vector>
#include <optional>
#include <set>

using U8  = uint8_t;
using U16 = uint16_t;
using U32 = uint32_t;
using U64 = uint64_t;

using I8  = int8_t;
using I16 = int16_t;
using I32 = int32_t;
using I64 = int64_t;

using F32 = float;
using F64 = double;

template <typename T>
using Vector = std::vector<T>;

template <typename T>
using Optional = std::optional<T>;

template <typename T>
using Set = std::set<T>;

#define U8(x)  static_cast<U8>(x)
#define U16(x) static_cast<U16>(x)
#define U32(x) static_cast<U32>(x)
#define U64(x) static_cast<U64>(x)

#define I8(x)  static_cast<I8>(x)
#define I16(x) static_cast<I16>(x)
#define I32(x) static_cast<I32>(x)
#define I64(x) static_cast<I64>(x)
