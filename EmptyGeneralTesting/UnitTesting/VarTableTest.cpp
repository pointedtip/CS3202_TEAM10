#include <cppunit\config\SourcePrefix.h>
#include "..\SPA\PKB\VarTable.h"
#include "VarTableTest.h"
#include "..\SPA\Exception\IndexNotFoundException.h"

#include <iostream>
#include <string>

void VarTableTest::setUp() {
	VarTable::ClearData();
}

void VarTableTest::tearDown() {
	VarTable::ClearData();
}

CPPUNIT_TEST_SUITE_REGISTRATION(VarTableTest);

void VarTableTest::testInsert() {
	VarTable::ClearData();

	int size = 0, varIndex = 0; 
	string varName;

	// insert a new variable to a new VarTable
	varIndex = VarTable::InsertVar("x2");
	CPPUNIT_ASSERT_EQUAL(0, varIndex);
	varIndex = VarTable::InsertVar("x1");
	CPPUNIT_ASSERT_EQUAL(1, varIndex);
	varIndex = VarTable::InsertVar("abcedfghijklmnop");
	CPPUNIT_ASSERT_EQUAL(2, varIndex);

	// x2 inserted first to check that the order of x1 and x2 are nto being rearranged
	
	size = VarTable::GetSize();
	CPPUNIT_ASSERT_EQUAL(3, size);
	
	varName = VarTable::GetVarName(0);
	CPPUNIT_ASSERT(varName == "x2");

	varName = VarTable::GetVarName(1);
	CPPUNIT_ASSERT(varName == "x1");
	
	// insert a variable that already exists in the VarTable
	int newIndex;
	newIndex = VarTable::InsertVar("x2");
	CPPUNIT_ASSERT_EQUAL(0, newIndex);
	CPPUNIT_ASSERT_EQUAL(3, size);
	
	newIndex = VarTable::InsertVar("x1");
	CPPUNIT_ASSERT_EQUAL(1, newIndex);
	CPPUNIT_ASSERT_EQUAL(3, size);

	// test white spaces...

}

void VarTableTest::testGetIndexOf() {
	VarTable::ClearData();
	int varIndex;

	// test for repeated insertions 
	// test that indexes are assigned based on the order variables are inserted
	VarTable::InsertVar("b");
	VarTable::InsertVar("a");
	VarTable::InsertVar("b");
	VarTable::InsertVar("c");
	VarTable::InsertVar("123");

	varIndex = VarTable::GetIndexOf("b");
	CPPUNIT_ASSERT_EQUAL(0, varIndex);
	varIndex = VarTable::GetIndexOf("a");
	CPPUNIT_ASSERT_EQUAL(1, varIndex);
	varIndex = VarTable::GetIndexOf("123");
	CPPUNIT_ASSERT_EQUAL(3, varIndex);

	// test for variables that do not exist
	varIndex = VarTable::GetIndexOf("z");
	CPPUNIT_ASSERT_EQUAL(-1, varIndex);
	
	// test white spaces...

}

void VarTableTest::testGetSize() {
	VarTable::ClearData();
	int size;

	// test for empty varTable
	size =  VarTable::GetSize();
	CPPUNIT_ASSERT_EQUAL(0, size);

	// test for repeated insertions
	VarTable::InsertVar("a");
	VarTable::InsertVar("a");
	VarTable::InsertVar("b");
	VarTable::InsertVar("a");
	size = VarTable::GetSize();
	CPPUNIT_ASSERT_EQUAL(2, size);

}

void VarTableTest::testGetVarName() {
	VarTable::ClearData();
	string varName;

	// test get a non-existent variable
	CPPUNIT_ASSERT_THROW(VarTable::GetVarName(0), IndexNotFoundException);
	CPPUNIT_ASSERT_THROW(VarTable::GetVarName(-1), IndexNotFoundException);

	VarTable::InsertVar("a");
	VarTable::InsertVar("a");
	VarTable::InsertVar("b");
	VarTable::InsertVar("a");

	// regular GetVarName
	varName = VarTable::GetVarName(1);
	CPPUNIT_ASSERT("b" == varName);

}

// insert other methods below here
// add a comment before each method to indicate its purpose