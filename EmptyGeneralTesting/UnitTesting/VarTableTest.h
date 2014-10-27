#pragma once

#define TestVarTable_h

#include <cppunit\extensions\HelperMacros.h>

class VarTableTest : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE(VarTableTest);
	CPPUNIT_TEST(testConstructor);
	CPPUNIT_TEST(testInsert);
	CPPUNIT_TEST(testGetIndexOf);
	// add other methods to test here
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	void testConstructor();
	void testInsert();
	void testGetIndexOf();
	// void testGetSize();
	// void testGetVarName

};
