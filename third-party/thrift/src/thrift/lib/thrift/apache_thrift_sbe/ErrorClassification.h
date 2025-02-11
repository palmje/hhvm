/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _APACHE_THRIFT_SBE_ERRORCLASSIFICATION_CXX_H_
#define _APACHE_THRIFT_SBE_ERRORCLASSIFICATION_CXX_H_

#if __cplusplus >= 201103L
#define SBE_CONSTEXPR constexpr
#define SBE_NOEXCEPT noexcept
#else
#define SBE_CONSTEXPR
#define SBE_NOEXCEPT
#endif

#if __cplusplus >= 201703L
#include <string_view>
#define SBE_NODISCARD [[nodiscard]]
#else
#define SBE_NODISCARD
#endif

#if !defined(__STDC_LIMIT_MACROS)
#define __STDC_LIMIT_MACROS 1
#endif

#include <cstdint>
#include <cstring>
#include <iomanip>
#include <limits>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

#if defined(WIN32) || defined(_WIN32)
#define SBE_BIG_ENDIAN_ENCODE_16(v) _byteswap_ushort(v)
#define SBE_BIG_ENDIAN_ENCODE_32(v) _byteswap_ulong(v)
#define SBE_BIG_ENDIAN_ENCODE_64(v) _byteswap_uint64(v)
#define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define SBE_BIG_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#define SBE_BIG_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#define SBE_BIG_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define SBE_LITTLE_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#define SBE_LITTLE_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#define SBE_LITTLE_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#define SBE_BIG_ENDIAN_ENCODE_16(v) (v)
#define SBE_BIG_ENDIAN_ENCODE_32(v) (v)
#define SBE_BIG_ENDIAN_ENCODE_64(v) (v)
#else
#error \
    "Byte Ordering of platform not determined. Set __BYTE_ORDER__ manually before including this file."
#endif

#if !defined(SBE_BOUNDS_CHECK_EXPECT)
#if defined(SBE_NO_BOUNDS_CHECK)
#define SBE_BOUNDS_CHECK_EXPECT(exp, c) (false)
#elif defined(_MSC_VER)
#define SBE_BOUNDS_CHECK_EXPECT(exp, c) (exp)
#else
#define SBE_BOUNDS_CHECK_EXPECT(exp, c) (__builtin_expect(exp, c))
#endif

#endif

#define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#define SBE_NULLVALUE_INT8 (std::numeric_limits<std::int8_t>::min)()
#define SBE_NULLVALUE_INT16 (std::numeric_limits<std::int16_t>::min)()
#define SBE_NULLVALUE_INT32 (std::numeric_limits<std::int32_t>::min)()
#define SBE_NULLVALUE_INT64 (std::numeric_limits<std::int64_t>::min)()
#define SBE_NULLVALUE_UINT8 (std::numeric_limits<std::uint8_t>::max)()
#define SBE_NULLVALUE_UINT16 (std::numeric_limits<std::uint16_t>::max)()
#define SBE_NULLVALUE_UINT32 (std::numeric_limits<std::uint32_t>::max)()
#define SBE_NULLVALUE_UINT64 (std::numeric_limits<std::uint64_t>::max)()

#include "ErrorBlame.h"
#include "ErrorKind.h"
#include "ErrorSafety.h"

namespace apache {
namespace thrift {
namespace sbe {

class ErrorClassification {
 private:
  char* m_buffer = nullptr;
  std::uint64_t m_bufferLength = 0;
  std::uint64_t m_offset = 0;
  std::uint64_t m_actingVersion = 0;

 public:
  enum MetaAttribute { EPOCH, TIME_UNIT, SEMANTIC_TYPE, PRESENCE };

  union sbe_float_as_uint_u {
    float fp_value;
    std::uint32_t uint_value;
  };

  union sbe_double_as_uint_u {
    double fp_value;
    std::uint64_t uint_value;
  };

  ErrorClassification() = default;

  ErrorClassification(
      char* buffer,
      const std::uint64_t offset,
      const std::uint64_t bufferLength,
      const std::uint64_t actingVersion)
      : m_buffer(buffer),
        m_bufferLength(bufferLength),
        m_offset(offset),
        m_actingVersion(actingVersion) {
    if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + 3) > m_bufferLength), false)) {
      throw std::runtime_error("buffer too short for flyweight [E107]");
    }
  }

  ErrorClassification(
      char* buffer,
      const std::uint64_t bufferLength,
      const std::uint64_t actingVersion)
      : ErrorClassification(buffer, 0, bufferLength, actingVersion) {}

  ErrorClassification(char* buffer, const std::uint64_t bufferLength)
      : ErrorClassification(buffer, 0, bufferLength, sbeSchemaVersion()) {}

  ErrorClassification& wrap(
      char* buffer,
      const std::uint64_t offset,
      const std::uint64_t actingVersion,
      const std::uint64_t bufferLength) {
    m_buffer = buffer;
    m_bufferLength = bufferLength;
    m_offset = offset;
    m_actingVersion = actingVersion;

    if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + 3) > m_bufferLength), false)) {
      throw std::runtime_error("buffer too short for flyweight [E107]");
    }

    return *this;
  }

  SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t encodedLength()
      SBE_NOEXCEPT {
    return 3;
  }

  SBE_NODISCARD std::uint64_t offset() const SBE_NOEXCEPT { return m_offset; }

  SBE_NODISCARD const char* buffer() const SBE_NOEXCEPT { return m_buffer; }

  SBE_NODISCARD char* buffer() SBE_NOEXCEPT { return m_buffer; }

  SBE_NODISCARD std::uint64_t bufferLength() const SBE_NOEXCEPT {
    return m_bufferLength;
  }

  SBE_NODISCARD std::uint64_t actingVersion() const SBE_NOEXCEPT {
    return m_actingVersion;
  }

  SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaId() SBE_NOEXCEPT {
    return static_cast<std::uint16_t>(1);
  }

  SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion()
      SBE_NOEXCEPT {
    return static_cast<std::uint16_t>(0);
  }

  SBE_NODISCARD static const char* errorKindMetaAttribute(
      const MetaAttribute metaAttribute) SBE_NOEXCEPT {
    switch (metaAttribute) {
      case MetaAttribute::PRESENCE:
        return "required";
      default:
        return "";
    }
  }

  static SBE_CONSTEXPR std::uint16_t errorKindId() SBE_NOEXCEPT { return -1; }

  SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t errorKindSinceVersion()
      SBE_NOEXCEPT {
    return 0;
  }

  SBE_NODISCARD bool errorKindInActingVersion() SBE_NOEXCEPT { return true; }

  SBE_NODISCARD static SBE_CONSTEXPR std::size_t errorKindEncodingOffset()
      SBE_NOEXCEPT {
    return 0;
  }

  SBE_NODISCARD static SBE_CONSTEXPR std::size_t errorKindEncodingLength()
      SBE_NOEXCEPT {
    return 1;
  }

  SBE_NODISCARD std::uint8_t errorKindRaw() const SBE_NOEXCEPT {
    std::uint8_t val;
    std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint8_t));
    return (val);
  }

  SBE_NODISCARD ErrorKind::Value errorKind() const {
    std::uint8_t val;
    std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint8_t));
    return ErrorKind::get((val));
  }

  ErrorClassification& errorKind(const ErrorKind::Value value) SBE_NOEXCEPT {
    std::uint8_t val = (value);
    std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint8_t));
    return *this;
  }

  SBE_NODISCARD static const char* errorBlameMetaAttribute(
      const MetaAttribute metaAttribute) SBE_NOEXCEPT {
    switch (metaAttribute) {
      case MetaAttribute::PRESENCE:
        return "required";
      default:
        return "";
    }
  }

  static SBE_CONSTEXPR std::uint16_t errorBlameId() SBE_NOEXCEPT { return -1; }

  SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t errorBlameSinceVersion()
      SBE_NOEXCEPT {
    return 0;
  }

  SBE_NODISCARD bool errorBlameInActingVersion() SBE_NOEXCEPT { return true; }

  SBE_NODISCARD static SBE_CONSTEXPR std::size_t errorBlameEncodingOffset()
      SBE_NOEXCEPT {
    return 1;
  }

  SBE_NODISCARD static SBE_CONSTEXPR std::size_t errorBlameEncodingLength()
      SBE_NOEXCEPT {
    return 1;
  }

  SBE_NODISCARD std::uint8_t errorBlameRaw() const SBE_NOEXCEPT {
    std::uint8_t val;
    std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::uint8_t));
    return (val);
  }

  SBE_NODISCARD ErrorBlame::Value errorBlame() const {
    std::uint8_t val;
    std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::uint8_t));
    return ErrorBlame::get((val));
  }

  ErrorClassification& errorBlame(const ErrorBlame::Value value) SBE_NOEXCEPT {
    std::uint8_t val = (value);
    std::memcpy(m_buffer + m_offset + 1, &val, sizeof(std::uint8_t));
    return *this;
  }

  SBE_NODISCARD static const char* errorSafetyMetaAttribute(
      const MetaAttribute metaAttribute) SBE_NOEXCEPT {
    switch (metaAttribute) {
      case MetaAttribute::PRESENCE:
        return "required";
      default:
        return "";
    }
  }

  static SBE_CONSTEXPR std::uint16_t errorSafetyId() SBE_NOEXCEPT { return -1; }

  SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t errorSafetySinceVersion()
      SBE_NOEXCEPT {
    return 0;
  }

  SBE_NODISCARD bool errorSafetyInActingVersion() SBE_NOEXCEPT { return true; }

  SBE_NODISCARD static SBE_CONSTEXPR std::size_t errorSafetyEncodingOffset()
      SBE_NOEXCEPT {
    return 2;
  }

  SBE_NODISCARD static SBE_CONSTEXPR std::size_t errorSafetyEncodingLength()
      SBE_NOEXCEPT {
    return 1;
  }

  SBE_NODISCARD std::uint8_t errorSafetyRaw() const SBE_NOEXCEPT {
    std::uint8_t val;
    std::memcpy(&val, m_buffer + m_offset + 2, sizeof(std::uint8_t));
    return (val);
  }

  SBE_NODISCARD ErrorSafety::Value errorSafety() const {
    std::uint8_t val;
    std::memcpy(&val, m_buffer + m_offset + 2, sizeof(std::uint8_t));
    return ErrorSafety::get((val));
  }

  ErrorClassification& errorSafety(const ErrorSafety::Value value)
      SBE_NOEXCEPT {
    std::uint8_t val = (value);
    std::memcpy(m_buffer + m_offset + 2, &val, sizeof(std::uint8_t));
    return *this;
  }

  template <typename CharT, typename Traits>
  friend std::basic_ostream<CharT, Traits>& operator<<(
      std::basic_ostream<CharT, Traits>& builder, ErrorClassification& writer) {
    builder << '{';
    builder << R"("errorKind": )";
    builder << '"' << writer.errorKind() << '"';

    builder << ", ";
    builder << R"("errorBlame": )";
    builder << '"' << writer.errorBlame() << '"';

    builder << ", ";
    builder << R"("errorSafety": )";
    builder << '"' << writer.errorSafety() << '"';

    builder << '}';

    return builder;
  }
};

} // namespace sbe
} // namespace thrift
} // namespace apache

#endif
