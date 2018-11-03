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

#include <LBFL.h>
#include <new>

// --- ClassDescriptor Implement Start ---

LBFL::ClassDescriptor::~ClassDescriptor()
{
	delete[] members;
	delete[] functions;
}

LBFL::AccessLevel LBFL::ClassDescriptor::GetAccessLevel()
{
	return a_level;
}

std::string LBFL::ClassDescriptor::GetNamespace()
{
	return ns;
}

std::string LBFL::ClassDescriptor::GetClassName()
{
	return cn;
}

int LBFL::ClassDescriptor::GetSize()
{
	return size;
}

LBFL::TypeDescriptor *LBFL::ClassDescriptor::GetMemberVariables()
{
	return members;
}

LBFL::FunctionDescriptor *LBFL::ClassDescriptor::GetFunctions()
{
	return functions;
}

std::string LBFL::ClassDescriptor::toString()
{
	// TODO
	return "";
}

// --- ClassDescriptor Implement End ---

// --- LObjectCodeFile Implement Start ---

LBFL::LObjectCodeFile::~LObjectCodeFile()
{
	delete[] data;
	delete[] classes;
}

int LBFL::LObjectCodeFile::GetRevision()
{
	return revision;
}

int LBFL::LObjectCodeFile::GetLength()
{
	return length;
}

LBFL::ClassDescriptor *LBFL::LObjectCodeFile::GetClasses()
{
	return classes;
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