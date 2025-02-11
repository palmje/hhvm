/**
 * Autogenerated by Thrift for thrift/compiler/test/fixtures/any/src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/any/gen-cpp2/module_data.h"

#include <thrift/lib/cpp2/gen/module_data_cpp.h>

FOLLY_CLANG_DISABLE_WARNING("-Wunused-macros")

#if defined(__GNUC__) && defined(__linux__) && !FOLLY_MOBILE
// These attributes are applied to the static data members to ensure that they
// are not stripped from the compiled binary, in order to keep them available
// for use by debuggers at runtime.
//
// The "used" attribute is required to ensure the compiler always emits unused
// data.
//
// The "section" attribute is required to stop the linker from stripping used
// data. It works by forcing all of the data members (both used and unused ones)
// into the same section. As the linker strips data on a per-section basis, it
// is then unable to remove unused data without also removing used data.
// This has a similar effect to the "retain" attribute, but works with older
// toolchains.
#define THRIFT_DATA_MEMBER [[gnu::used]] [[gnu::section(".rodata.thrift.data")]]
#else
#define THRIFT_DATA_MEMBER
#endif

namespace apache {
namespace thrift {

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::detail::MyStruct>::name = "MyStruct";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::detail::MyStruct>::fields_names = {{
  "myString",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::detail::MyStruct>::fields_ids = {{
  1,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::detail::MyStruct>::fields_types = {{
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::detail::MyStruct>::storage_names = {{
  "__fbthrift_field_myString",
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::detail::MyStruct>::isset_indexes = {{
  0,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyUnion>::name = "MyUnion";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyUnion>::fields_names = {{
  "myString",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyUnion>::fields_ids = {{
  1,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyUnion>::fields_types = {{
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyUnion>::storage_names = {{
  "myString",
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyUnion>::isset_indexes = {{
  0,
}};

THRIFT_DATA_MEMBER const folly::StringPiece TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyException>::name = "MyException";
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyException>::fields_names = {{
  "myString",
}};
THRIFT_DATA_MEMBER const std::array<int16_t, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyException>::fields_ids = {{
  1,
}};
THRIFT_DATA_MEMBER const std::array<protocol::TType, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyException>::fields_types = {{
  TType::T_STRING,
}};
THRIFT_DATA_MEMBER const std::array<folly::StringPiece, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyException>::storage_names = {{
  "__fbthrift_field_myString",
}};
THRIFT_DATA_MEMBER const std::array<int, 1> TStructDataStorage<::facebook::thrift::compiler::test::fixtures::any::MyException>::isset_indexes = {{
  0,
}};

} // namespace thrift
} // namespace apache
