#include "gtest/gtest.h"
#include "libs/queue.h"
#include <string>

using namespace std;

TEST(QueueTest, firstOne) {
    Queue<int> aQueue;
    aQueue.push(1);
	EXPECT_EQ(aQueue.front(), 1);
}
TEST(QueueTest, SecondOne) {
    Queue<int> anotherQueue(2);
    anotherQueue.push(6);
    anotherQueue.push(7);
    anotherQueue.push(8);
    anotherQueue.push(9);
    EXPECT_EQ(anotherQueue.front(), 9);
    EXPECT_EQ(anotherQueue.get_size(), 4);
}

TEST(QueueTest, FirstPop) {
    Queue<int> anotherQueue(2);
    anotherQueue.push(6);
    anotherQueue.push(7);
    anotherQueue.push(8);
    anotherQueue.push(9);
    EXPECT_EQ(anotherQueue.front(), 9);
    EXPECT_EQ(anotherQueue.get_size(), 4);
    anotherQueue.pop();
    EXPECT_EQ(anotherQueue.front(), 8);
    EXPECT_EQ(anotherQueue.get_size(), 3);
    anotherQueue.pop();
    EXPECT_EQ(anotherQueue.front(), 7);
    EXPECT_EQ(anotherQueue.get_size(), 2);
    anotherQueue.pop();
    anotherQueue.pop();
    EXPECT_THROW(anotherQueue.front(), std::invalid_argument);
}