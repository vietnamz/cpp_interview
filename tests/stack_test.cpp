#include "gtest/gtest.h"
#include "libs/stack.h"
#include <string>

using namespace std;

TEST(stackTest, firstOne) {
    Stack<int> aStack;
    aStack.push(10);
    aStack.push(24);
    aStack.push(1);
    aStack.push(4);
    aStack.push(23);
    aStack.push(56);
	EXPECT_EQ(aStack.front(), 56);
    aStack.pop();
    EXPECT_EQ(aStack.max(), 24);
}