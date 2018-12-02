/*
 * Copyright 2018 Chenxi Xu
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

/*
 * Header for the structs of LLTC's binary files
 */

#ifndef LBFL_BINARY_H
#define LBFL_BINARY_H

#include <cstdint>

namespace LBFL
{

	// shorthands for int types
	// ux -> unsigned int that contains x bytes
	using u1 = uint8_t;
	using u2 = uint16_t;
	using u4 = uint32_t;
	using u8 = uint64_t;

	struct LBytecodeHeader
	{
		u4 magic;
		u2 revision;
		u4 constant_size;
	};

	struct LObjectHeader
	{
		u4 magic;
		u2 revision;
		u2 class_count;
		u4 string_location;
		u4 text_location;
	};

	struct LClassInfo
	{
		u4 size;
		u1 access_flags;
		u4 namespace_name;
		u4 class_name;
		u4 super_class_name; // Multi-inheriting is currently not supported
		u2 field_count;
		u2 procedure_location;
		u2 procedure_count;
	};

	struct LFieldInfo
	{
		u1 access_flags;
		u4 name;
		u4 type_descriptor;
	};

	struct LProcedureInfo
	{
		u1 access_flags;
		u4 name;
		u4 return_type_descriptor;
		u2 parameter_counts;
		u4 text_length;
		u4 text_offset;
	};
}

#endif //LBFL_BINARY_H
