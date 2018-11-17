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

#include "LBFL.h"
#include <new>

// --- ClassDescriptor Implement Start ---

std::string LBFL::ClassDescriptor::toString()
{
	// TODO
	return "";
}

LBFL::AccessLevel LBFL::ClassDescriptor::GetAccessLevel() const
{
	return a_level;
}

void LBFL::ClassDescriptor::SetAccessLevel( LBFL::AccessLevel accessLevel )
{
	ClassDescriptor::a_level = accessLevel;
}

const std::string &LBFL::ClassDescriptor::GetNamespace() const
{
	return ns;
}

void LBFL::ClassDescriptor::SetNamespace( const std::string &ns )
{
	ClassDescriptor::ns = ns;
}

const std::string &LBFL::ClassDescriptor::GetName() const
{
	return cn;
}

void LBFL::ClassDescriptor::GetName( const std::string &name )
{
	ClassDescriptor::cn = name;
}

int LBFL::ClassDescriptor::getSize() const
{
	return size;
}

const std::vector<LBFL::FunctionDescriptor> &LBFL::ClassDescriptor::getFunctions() const
{
	return functions;
}

void LBFL::ClassDescriptor::setFunctions( const std::vector<LBFL::FunctionDescriptor> &functions )
{
	ClassDescriptor::functions = functions;
}

const std::vector<std::pair<LBFL::TypeDescriptor, std::string>> &LBFL::ClassDescriptor::GetMemberVariables() const
{
	return members;
}

void LBFL::ClassDescriptor::GetMemberVariables(
		const std::vector<std::pair<LBFL::TypeDescriptor, std::string>> &members )
{
	ClassDescriptor::members = members;
}

// --- ClassDescriptor Implement End ---

// --- LObjectCodeFile Implement Start ---

LBFL::LObjectCodeFile::~LObjectCodeFile()
{
	delete[] data;
}

int LBFL::LObjectCodeFile::GetRevision()
{
	return revision;
}

int LBFL::LObjectCodeFile::GetLength()
{
	return length;
}

int LBFL::LObjectCodeFile::GetConstantPosition()
{
	return c_pos;
}

int LBFL::LObjectCodeFile::GetConstantSize()
{
	return c_size;
}

int LBFL::LObjectCodeFile::GetCodeSegmentPosition()
{
	return t_pos;
}

int LBFL::LObjectCodeFile::GetCodeSegmentSize()
{
	return t_size;
}

char *LBFL::LObjectCodeFile::GetRawData()
{
	return data;
}
// --- LObjectCodeFile Implement End ---

// --- LByteCodeFile Implement Start ---

LBFL::LByteCodeFile::~LByteCodeFile()
{
	delete[] data;
}

int LBFL::LByteCodeFile::GetRevision()
{
	return revision;
}

int LBFL::LByteCodeFile::GetLength()
{
	return length;
}

int LBFL::LByteCodeFile::GetConstantPosition()
{
	return c_pos;
}

int LBFL::LByteCodeFile::GetConstantSize()
{
	return c_size;
}

int LBFL::LByteCodeFile::GetCodeSegmentPosition()
{
	return t_pos;
}

int LBFL::LByteCodeFile::GetCodeSegmentSize()
{
	return t_size;
}

char *LBFL::LByteCodeFile::GetRawData()
{
	return data;
}

// --- LByteCodeFile Implement End ---


LBFL::AccessLevel LBFL::VariablesDescriptor::GetAccessLevel() const
{
	return a_level;
}

void LBFL::VariablesDescriptor::SetAccessLevel( LBFL::AccessLevel a_level )
{
	VariablesDescriptor::a_level = a_level;
}

const LBFL::TypeDescriptor &LBFL::VariablesDescriptor::GetType() const
{
	return type;
}

void LBFL::VariablesDescriptor::SetType( const LBFL::TypeDescriptor &type )
{
	VariablesDescriptor::type = type;
}

const std::string &LBFL::VariablesDescriptor::GetName() const
{
	return name;
}

void LBFL::VariablesDescriptor::SetName( const std::string &name )
{
	VariablesDescriptor::name = name;
}

const LBFL::TypeDescriptor &LBFL::FunctionDescriptor::GetReturnType() const
{
	return r_type;
}

void LBFL::FunctionDescriptor::SetReturnType( const LBFL::TypeDescriptor &returnType )
{
	FunctionDescriptor::r_type = returnType;
}

LBFL::AccessLevel LBFL::FunctionDescriptor::GetAccessLevel() const
{
	return a_level;
}

void LBFL::FunctionDescriptor::SetAccessLevel( LBFL::AccessLevel a_level )
{
	FunctionDescriptor::a_level = a_level;
}

const std::string &LBFL::FunctionDescriptor::getName() const
{
	return name;
}

void LBFL::FunctionDescriptor::setName( const std::string &name )
{
	FunctionDescriptor::name = name;
}

const std::vector<std::pair<LBFL::TypeDescriptor, std::string>> &LBFL::FunctionDescriptor::GetParameterList() const
{
	return p_list;
}

void LBFL::FunctionDescriptor::SetParameterList(
		const std::vector<std::pair<LBFL::TypeDescriptor, std::string>> &parameters )
{
	FunctionDescriptor::p_list = parameters;
}

bool LBFL::FunctionDescriptor::isNative() const
{
	return native;
}

void LBFL::FunctionDescriptor::setNative( bool native )
{
	FunctionDescriptor::native = native;
}

int LBFL::FunctionDescriptor::GetTextPosition() const
{
	return t_pos;
}

// PrimitiveTypeDescriptor

LBFL::PrimitiveType LBFL::PrimitiveTypeDescriptor::GetType() const
{
	return type;
}

void LBFL::PrimitiveTypeDescriptor::SetType( LBFL::PrimitiveType type )
{
	PrimitiveTypeDescriptor::type = type;
}

void LBFL::PrimitiveTypeDescriptor::LoadFromBinary( char *data )
{
	type = (PrimitiveType) *data;
}

char *LBFL::PrimitiveTypeDescriptor::DumpToBinary() const
{
	return new char[1]{ (char) type };
}

std::string LBFL::PrimitiveTypeDescriptor::ToString() const
{
	switch (type)
	{
		case PrimitiveType::INT:
			return "I";
		case PrimitiveType::LONG:
			return "L";
		case PrimitiveType::SHORT:
			return "S";
		case PrimitiveType::BYTE:
			return "Y";
		case PrimitiveType::CHAR:
			return "X";
		case PrimitiveType::FLOAT:
			return "F";
		case PrimitiveType::DOUBLE:
			return "D";
		case PrimitiveType::BOOLEAN:
			return "B";
		case PrimitiveType::POINTER:
			return "P";
	}
}

int LBFL::PrimitiveTypeDescriptor::GetSize() const
{
	switch (type)
	{
		case PrimitiveType::INT:
		case PrimitiveType::BOOLEAN:
		case PrimitiveType::FLOAT:
			return 32;
		case PrimitiveType::LONG:
		case PrimitiveType::DOUBLE:
		case PrimitiveType::POINTER:
			return 64;
		case PrimitiveType::SHORT:
		case PrimitiveType::CHAR:
			return 16;
		case PrimitiveType::BYTE:
			return 4;
	}
}

// ClassTypeDescriptor

const std::string &LBFL::ClassTypeDescriptor::GetName() const
{
	return name;
}

void LBFL::ClassTypeDescriptor::SetName( const std::string &name )
{
	ClassTypeDescriptor::name = name;
}

// CombinedTypeDescriptor

LBFL::CombinedType LBFL::CombinedTypeDescriptor::GetType() const
{
	return type;
}

void LBFL::CombinedTypeDescriptor::SetType( LBFL::CombinedType type )
{
	CombinedTypeDescriptor::type = type;
}

const LBFL::TypeDescriptor &LBFL::CombinedTypeDescriptor::GetCombinedType() const
{
	return combinedType;
}

void LBFL::CombinedTypeDescriptor::SetCombinedType( const LBFL::TypeDescriptor &combinedType )
{
	CombinedTypeDescriptor::combinedType = combinedType;
}
