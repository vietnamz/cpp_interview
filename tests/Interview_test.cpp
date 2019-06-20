#include "gtest/gtest.h"
#include "libs/Interview.h"
#include <string>

using namespace std;

TEST(HelloWorld, HelloWorld) {
	//EXPECT_EQ(getHelloWorld(), string("Hello World"));
}


TEST(HelloWorld, kLastLine9) {
	//EXPECT_EQ(kLastLines("test.txt", 9), string("FOOBARHOPELESSLASTTIMEIMEETnext"));
}

TEST(HelloWorld, kLastLine8) {
	//EXPECT_EQ(kLastLines("test.txt", 8), string("BARHOPELESSLASTTIMEIMEETnext"));
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

TEST(HelloWorld, segregate_character) {
	vector<char> list_of_char = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
	segregate_character(list_of_char);
	vector<char> result({'R', 'R', 'R', 'G', 'G', 'B', 'B'});
	EXPECT_EQ(list_of_char, result);
}

TEST(HelloWorld, get_sub_string) {
	string input = "\"a,b,c\",\"\",\"c,d,e\"";
	vector<string> out = {"a,b,c","c,d,e"};
	EXPECT_EQ(break_string(input), out) ;

}

TEST(HelloWorld, count_to_file) {
	EXPECT_EQ(count_to_10(),0);
}