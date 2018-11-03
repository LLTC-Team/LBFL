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
#ifndef LBFL_LBFL_H
#define LBFL_LBFL_H

#include <string>
#include <cinttypes>
#include <istream>
#include <ostream>

namespace LBFL
{
	enum class AccessLevel : u_int8_t
	{
		PRIVATE = 1, NAMESPACE = 2, PROTECTED = 3, PUBLIC = 4;
	};

	struct TypeDescriptor
	{
		std::string ToString();

		int GetSize();
	};

	struct FunctionDescriptor
	{
		AccessLevel GetAccessLevel();

		std::string GetName();

		TypeDescriptor GetReturnType();

		TypeDescriptor *GetParameterTypes();

		bool IsNative();

		int GetCodeSegmentPosition();

		std::string ToString();
	};

	struct ClassDescriptor
	{
		~ClassDescriptor();

		AccessLevel GetAccessLevel();

		std::string GetNamespace();

		std::string GetClassName();

		int GetSize();

		TypeDescriptor *GetMemberVariables();

		FunctionDescriptor *GetFunctions();

		std::string toString();
	private:
		AccessLevel a_level;
		std::string ns, cn;
		int size;
		TypeDescriptor *members;
		FunctionDescriptor *functions;
	};

	struct LObjectCodeFile
	{
		~LObjectCodeFile();

		int GetRevision();

		int GetLength();

		ClassDescriptor *GetClasses();

		int GetConstantPosition();

		int GetConstantSize();

		int GetCodeSegmentPosition();

		int GetCodeSegmentSize();

		char *GetRawData();

	private:
		char *data;
		ClassDescriptor *classes;
		int revision, length, c_pos, c_size, t_pos, t_size;
	};

	struct LByteCodeFile
	{
		~LByteCodeFile();

		int GetRevision();

		int GetLength();

		int GetConstantPosition();

		int GetConstantSize();

		int GetCodeSegmentPosition();

		int GetCodeSegmentSize();

		char *GetRawData();

	private:
		char *data;
		int revision, length, c_pos, c_size, t_pos, t_size;
	};

	LObjectCodeFile *ReadAsObjectCode( std::istream &in );

	void WriteObjectCode( LObjectCodeFile *code, std::ostream &out )

	LByteCodeFile *ReadAsByteCode( std::istream &in );

	void WriteByteCode( LByteCodeFile *code, std::ostream &out );

}

#endif //LBFL_LBFL_H
