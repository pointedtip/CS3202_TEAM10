#pragma once

#define ParserTest_h

#include "cppunit\extensions\HelperMacros.h"
#include "Parser\Parser.h"

class ParserTest : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE(ParserTest);
	CPPUNIT_TEST(TestSimpleAssignmentParsing);
	CPPUNIT_TEST(TestAdditionParsing);
	CPPUNIT_TEST(TestWhileParsing);
	CPPUNIT_TEST(TestNestedWhileParsing);
	CPPUNIT_TEST_SUITE_END();

public:
	static const string TESTFILE_DIRECTORY;
	void setUp();
	void tearDown();

	ParserTest();

	void TestSimpleAssignmentParsing();
	void TestAdditionParsing();
	void TestWhileParsing();
	void TestNestedWhileParsing();
};

