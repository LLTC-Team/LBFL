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

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <LBFL.h>
#include <iostream>

TEST_CASE( "Test Primitive Type Binary Serialization", "[LBFL][BinarySerialization]" )
{
	LBFL::PrimitiveTypeDescriptor pyd1, pyd2;
	pyd1.SetType( LBFL::PrimitiveType::SHORT );
	char *bin = pyd1.DumpToBinary();
	pyd2.LoadFromBinary( bin );
	std::cout << (int) pyd1.GetType() << std::endl << (int) pyd2.GetType() <<  std::endl;
	REQUIRE( pyd1.GetType() == pyd2.GetType());
}