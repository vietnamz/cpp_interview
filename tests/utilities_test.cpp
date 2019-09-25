#include "gtest/gtest.h"
#include "libs/utilities.h"
#include "libs/meal_combo.h"
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

TEST(HelloWorld, varadic_template) {
	EXPECT_EQ(test_variadic_template(), string("noo zoo foo"));
}

TEST(HelloWorld, add_summer) {
	EXPECT_EQ(add_sum_template(), 27);
}

TEST(HelloWorld, palindrome) {
	string word = "Deleveled";
	EXPECT_EQ(isPalindrome(word), true);
}

TEST(HelloWorld, find_non_duplicate) {
	vector<int> avec = { 6, 1, 3, 3, 3, 6, 6 };
	EXPECT_EQ(find_non_duplicate(avec), 1);
	vector<int> secondvec = { 13, 19, 13, 13 };
	EXPECT_EQ(find_non_duplicate(secondvec), 19);
}

TEST(HelloWorld, compositon_test) {
	Entree entree = "hotdog";
	Side side = "pizza";
	Drink drink;
	MealCombo mealCombo("FA");
	mealCombo.setEntree(&entree);
	mealCombo.setSide(&side);
	mealCombo.setDrink(&drink);
	EXPECT_EQ(mealCombo.openMealBag(), string("FA meal combo: hotdog, soda, pizza"));
}

TEST(HelloWorld, binaryan) {
	vector<int> a = { 1,0,2,0,0,0,2};
	int result = binarian_t(a);
	EXPECT_EQ(result,3);
}

TEST(HelloWorld, biggest_number) {
	int resutl = third_biggest_number(vector<int>({1,1,5,5,5}));

	EXPECT_EQ(resutl, INT_MIN);
}

TEST(HelloWorld, profit_sort) {
	vector<int> input = {2, 10, 13, 23, 33};
	int result = profit_sort(input, 7, 11);
	EXPECT_EQ(1, result);
	result = profit_sort(input, 10, 30);
	EXPECT_EQ(3, result);
	result = profit_sort(input, 1, 10);
	EXPECT_EQ(2, result);
	result = profit_sort(input, 2, 40);
	EXPECT_EQ(5, result);
	result = profit_sort(input, 5, 6);
	EXPECT_EQ(0, result);
}