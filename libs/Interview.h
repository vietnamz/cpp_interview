/*
 * Interview.h
 *
 *  Created on: Feb 23, 2019
 *      Author: delgemoon
 */

#ifndef LIBS_INTERVIEW_H_
#define LIBS_INTERVIEW_H_

#include <string>

using namespace std;

static const string HELLO_WORLD="Hello World";


const string& getHelloWorld();

const string kLastLines(string fileName, int k);

const int countWordOccurencies(const string book, string expectedWord);
void segregate_character(vector<char>& listOfChar);

vector<string> break_string(const string& input);
int count_to_10();

#endif /* LIBS_INTERVIEW_H_ */
