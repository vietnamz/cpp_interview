#include "gtest/gtest.h"
#include "libs/Interview.h"
#include <string>

using namespace std;

TEST(HelloWorld, HelloWorld) {
	EXPECT_EQ(getHelloWorld(), string("Hello World"));
}


TEST(HelloWorld, kLastLine9) {
	EXPECT_EQ(kLastLines("test.txt", 9), string("FOOBARHOPELESSLASTTIMEIMEETnext"));
}

TEST(HelloWorld, kLastLine8) {
	EXPECT_EQ(kLastLines("test.txt", 8), string("BARHOPELESSLASTTIMEIMEETnext"));
}

TEST(HelloWorld, kLastLineInvalid) {
	EXPECT_EQ(kLastLines("test.txt", 10), string("IMPOSSIBLE"));
}

TEST(HelloWorld, kLastLine0) {
	EXPECT_EQ(kLastLines("test.txt", 0), string(""));
}


TEST(HelloWorld, WordOccurences1) {
	EXPECT_EQ(countWordOccurencies("I hate what I do", "hate"), 1);
}
