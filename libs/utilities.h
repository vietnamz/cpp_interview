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


enum TrafficLight {
    red, green, yellow
};

enum CarColor {
    black, white, gray, silver,
    //green // can't have the color green in two enum
};

enum class Pet {
    dog, cat, bird
};
enum class Mammal {
    bear, cougar, coyate, dog
};

template<typename T> T rcatenate(T v) {
    return v;
}

template<typename T, typename... Args>
T rcatenate(T first, Args... args) {
    return rcatenate(args...) + " " + first;
}


template<typename T>
T summer(T args) {
    return args;
}

template<typename T, typename... Args>
T summer(T first, Args... args) {
    return summer(args...) + first;
}
static const string HELLO_WORLD="Hello World";


const string& getHelloWorld();

const string kLastLines(string fileName, int k);

const int countWordOccurencies(const string book, string expectedWord);
void segregate_character(vector<char>& listOfChar);


vector<string> break_string(const string& input);
int count_to_10();
string test_variadic_template();
int add_sum_template();

bool isPalindrome(string word);

int find_non_duplicate(const vector<int>& vec);
int binarian_t(vector<int>& t);

int third_biggest_number(const vector<int>& alist);

int profit_sort(vector<int>& profit, int left, int right);

#endif /* LIBS_INTERVIEW_H_ */
