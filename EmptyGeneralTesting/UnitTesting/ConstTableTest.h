#pragma once
#define ConstTableTest_h

#include <cppunit\extensions\HelperMacros.h>


class ConstTableTest : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE(ConstTableTest);
	CPPUNIT_TEST(testGetAllConst);
	// add other methods to test here
	CPPUNIT_TEST_SUITE_END();

public:
	ConstTableTest(void);
	void setUp();
	void tearDown();

	void testGetAllConst();
	// add other methods to test here

	~ConstTableTest(void);

};

