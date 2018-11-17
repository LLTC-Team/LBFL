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
#include <vector>
#include <utility>

namespace LBFL
{
	enum class AccessLevel : u_int8_t
	{
		PRIVATE = 1, NAMESPACE = 2, PROTECTED = 3, PUBLIC = 4;
	};

	class BinarySerialization
	{
	public:
		virtual void LoadFromBinary( char *data ) {}

		virtual char *DumpToBinary()
		{
			return nullptr;
		}
	};

	class TypeDescriptor : public BinarySerialization
	{
	public:

		std::string ToString();

		int GetSize();
	};

	class VariablesDescriptor : public BinarySerialization
	{
	public:
		AccessLevel GetAccessLevel() const;

		void SetAccessLevel( AccessLevel a_level );

		const TypeDescriptor &GetType() const;

		void SetType( const TypeDescriptor &type );

		const std::string &GetName() const;

		void SetName( const std::string &name );

	private:
		AccessLevel a_level;
		TypeDescriptor type;
		std::string name;
	};

	class FunctionDescriptor : public BinarySerialization
	{
	public:

		const TypeDescriptor &GetReturnType() const;

		void SetReturnType( const TypeDescriptor &returnType );

		AccessLevel GetAccessLevel() const;

		void SetAccessLevel( AccessLevel a_level );

		const std::string &getName() const;

		void setName( const std::string &name );

		const std::vector<std::pair<TypeDescriptor, std::string>> &GetParameterList() const;

		void SetParameterList( const std::vector<std::pair<TypeDescriptor, std::string>> &parameters );

		bool isNative() const;

		void setNative( bool native );

		int GetTextPosition() const;

		std::string ToString();

	private:
		TypeDescriptor r_type;
		AccessLevel a_level;
		std::string name;
		std::vector<std::pair<TypeDescriptor, std::string>> p_list;
		bool native;
		int t_pos;
	};

	class ClassDescriptor : public BinarySerialization
	{
	public:
		AccessLevel GetAccessLevel() const;

		void SetAccessLevel( AccessLevel accessLevel);

		const std::string &GetNamespace() const;

		void SetNamespace( const std::string &ns );

		const std::string &GetName() const;

		void GetName( const std::string &name );

		int getSize() const;

		const std::vector<std::pair<TypeDescriptor, std::string>> &GetMemberVariables() const;

		void GetMemberVariables( const std::vector<std::pair<TypeDescriptor, std::string>> &members );

		const std::vector<FunctionDescriptor> &getFunctions() const;

		void setFunctions( const std::vector<FunctionDescriptor> &functions );

		std::string toString();

	private:
		AccessLevel a_level;
		std::string ns, cn;
		int size;
		std::vector<std::pair<TypeDescriptor, std::string>> members;
		std::vector<FunctionDescriptor> functions;
	};

	class LObjectCodeFile : public BinarySerialization
	{
	public:

		~LObjectCodeFile();

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

	class LByteCodeFile : public BinarySerialization
	{
	public:

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

	void WriteObjectCode( LObjectCodeFile *code, std::ostream &out );

	LByteCodeFile *ReadAsByteCode( std::istream &in );

	void WriteByteCode( LByteCodeFile *code, std::ostream &out );

}

#endif //LBFL_LBFL_H
