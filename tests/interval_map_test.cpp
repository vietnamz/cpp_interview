#include "gtest/gtest.h"
#include "libs/interval_map.h"
#include <string>

using namespace std;

TEST(IntervalMapTest, firstOne) {
    interval_map<int, char> aMap('a');
    aMap.assign(1,5,'b');
    EXPECT_EQ(aMap[1], 'b');
    EXPECT_EQ(aMap[2], 'b');
    EXPECT_EQ(aMap[3], 'b');
    EXPECT_EQ(aMap[4], 'b');
    aMap.assign(3,5, 'c');
    EXPECT_EQ(aMap[3], 'c');
    EXPECT_EQ(aMap[4], 'c');
    aMap.assign(5, 10, 'f');
    EXPECT_EQ(aMap[10], 'a');
    EXPECT_EQ(aMap[9], 'f');
    aMap.assign(7,8,'g');
    EXPECT_EQ(aMap[7], 'g');
    EXPECT_EQ(aMap[8], 'f');
    aMap.assign(8, 6, 'm');
    EXPECT_EQ(aMap[6], 'f');
    EXPECT_EQ(aMap[7], 'g');
    EXPECT_EQ(aMap[8], 'f');
}

TEST(IntervalMapTest, EmptyRange)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(3, 3, 'B');
    EXPECT_EQ(m.m_map.count(3),0);

    m.assign(3, 2, 'B');
    EXPECT_EQ(m.m_map.count(2), 0);
    EXPECT_EQ(m.m_map.count(3), 0);
}


TEST(IntervalMapTest, TrivialRange)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 10, 'B');
    EXPECT_EQ(m[0],'A');
    for (int i = 1; i < 10; i++)
    {
        EXPECT_EQ(m[i],'B');
    }
    EXPECT_EQ(m[10], 'A');
}

TEST(IntervalMapTest, TrivialTwoRange)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 3, 'B');
    m.assign(6, 8, 'C');
    EXPECT_EQ(m[0], 'A');
    EXPECT_EQ(m[1], 'B');
    EXPECT_EQ(m[2], 'B');
    EXPECT_EQ(m[3], 'A');
    EXPECT_EQ(m[4], 'A');
    EXPECT_EQ(m[5], 'A');
    EXPECT_EQ(m[6], 'C');
    EXPECT_EQ(m[7], 'C');
    EXPECT_EQ(m[8], 'A');
}

TEST(IntervalMapTest, OverwriteLowest)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(std::numeric_limits<TestKeyType>::lowest(), 10000, 'B');
    EXPECT_EQ(m[0], 'B');
    EXPECT_EQ(m[9999], 'B');
    EXPECT_EQ(m[10000], 'A');
}

TEST(IntervalMapTest, Merge)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(std::numeric_limits<TestKeyType>::lowest(), 10, 'B');
    m.assign(10, 20, 'B');
    EXPECT_EQ(m[0], 'B');
    EXPECT_EQ(m[10], 'B');
    EXPECT_EQ(m[19], 'B');
    EXPECT_EQ(m[20], 'A');
}

TEST(IntervalMapTest, FloatKey)
{
    interval_map<TestFloatKeyType, TestValueType> m('A');
    m.assign(1.f, 5.f, 'B');
    EXPECT_EQ(m[0.f], 'A');
    EXPECT_EQ(m[.999999999f], 'B');
    EXPECT_EQ(m[1.f], 'B');
    EXPECT_EQ(m[4.999f], 'B');
    EXPECT_EQ(m[5.f], 'A');

}

TEST(IntervalMapTest, OverlappingRangeComplete)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(3, 5, 'B');
    m.assign(1, 6, 'C');
    EXPECT_EQ(m[0], 'A');
    EXPECT_EQ(m[1], 'C');
    EXPECT_EQ(m[2], 'C');
    EXPECT_EQ(m[3], 'C');
    EXPECT_EQ(m[4], 'C');
    EXPECT_EQ(m[5], 'C');
    EXPECT_EQ(m[6], 'A');
}

TEST(IntervalMapTest, OverlappingRangeInner)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 6, 'C');
    m.assign(3, 5, 'B');
    EXPECT_EQ(m[0],'A');
    EXPECT_EQ(m[1],'C');
    EXPECT_EQ(m[2], 'C');
    EXPECT_EQ(m[3],'B');
    EXPECT_EQ(m[4],'B');
    EXPECT_EQ(m[5],'C');
    EXPECT_EQ(m[6],'A');
}

TEST(IntervalMapTest, OverlappingRangeSmallToLarge)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(3, 6, 'C');
    EXPECT_EQ(m[0], 'A');
    EXPECT_EQ(m[1], 'B');
    EXPECT_EQ(m[2], 'B');
    EXPECT_EQ(m[3], 'C');
    EXPECT_EQ(m[4], 'C');
    EXPECT_EQ(m[5], 'C');
    EXPECT_EQ(m[6], 'A');
}

TEST(IntervalMapTest, OverlappingRangeLargeToSmall)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(3, 6, 'C');
    m.assign(1, 5, 'B');
    EXPECT_EQ(m[0],'A');
    EXPECT_EQ(m[1] , 'B');
    EXPECT_EQ(m[2] , 'B');
    EXPECT_EQ(m[3] , 'B');
    EXPECT_EQ(m[4] , 'B');
    EXPECT_EQ(m[5] , 'C');
    EXPECT_EQ(m[6] , 'A');
}

TEST(IntervalMapTest, ExtendingRangeBegin)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(3, 5, 'B');
    m.assign(1, 4, 'B');
    EXPECT_EQ(m[0] , 'A');
    EXPECT_EQ(m[1] , 'B');
    EXPECT_EQ(m[2] , 'B');
    EXPECT_EQ(m[3] , 'B');
    EXPECT_EQ(m[4] , 'B');
    EXPECT_EQ(m[5] , 'A');
}

TEST(IntervalMapTest, ExtendingRangeEnd)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(3, 6, 'B');
    EXPECT_EQ(m[0] , 'A');
    EXPECT_EQ(m[1] , 'B');
    EXPECT_EQ(m[2] , 'B');
    EXPECT_EQ(m[3] , 'B');
    EXPECT_EQ(m[4] , 'B');
    EXPECT_EQ(m[5] , 'B');
    EXPECT_EQ(m[6] , 'A');
}

TEST(IntervalMapTest, ExtendingRangeBothBeginEnd)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(2, 3, 'B');
    m.assign(1, 5, 'B');
    EXPECT_EQ(m[0] , 'A');
    EXPECT_EQ(m[1] , 'B');
    EXPECT_EQ(m[2] , 'B');
    EXPECT_EQ(m[3] , 'B');
    EXPECT_EQ(m[4] , 'B');
    EXPECT_EQ(m[5] , 'A');
}

TEST(IntervalMapTest, OverwriteEndValueSafety)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(2, 5, 'B');
    m.assign(5, 8, 'C');
    m.assign(4, 5, 'A');
    EXPECT_EQ(m[5], 'C');
    EXPECT_EQ(m[7], 'C');
    EXPECT_EQ(m[8], 'A');
}

TEST(IntervalMapTest, ReusingExistingRangeBothBeginEnd)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(2, 3, 'B');
    EXPECT_EQ(m[0] , 'A');
    EXPECT_EQ(m[1] , 'B');
    EXPECT_EQ(m[2] , 'B');
    EXPECT_EQ(m[3] , 'B');
    EXPECT_EQ(m[4] , 'B');
    EXPECT_EQ(m[5] , 'A');
}

TEST(IntervalMapTest, ReusingEnd)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(4, 6, 'A');
    EXPECT_EQ(m[0] , 'A');
    EXPECT_EQ(m[1] , 'B');
    EXPECT_EQ(m[2] , 'B');
    EXPECT_EQ(m[3] , 'B');
    EXPECT_EQ(m[4] , 'A');
    EXPECT_EQ(m[5] , 'A');
}

TEST(IntervalMapTest, RestoringInitial)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(1, 5, 'A');
    EXPECT_EQ(m[0] , 'A');
    EXPECT_EQ(m[1] , 'A');
    EXPECT_EQ(m[2] , 'A');
    EXPECT_EQ(m[3] , 'A');
    EXPECT_EQ(m[4] , 'A');
    EXPECT_EQ(m[5] , 'A');
}

TEST(IntervalMapTest, RestoringInitial2)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(1, 5, 'B');
    m.assign(0, 7, 'A');
    EXPECT_EQ(m[0] , 'A');
    EXPECT_EQ(m[1] , 'A');
    EXPECT_EQ(m[2] , 'A');
    EXPECT_EQ(m[3] , 'A');
    EXPECT_EQ(m[4] , 'A');
    EXPECT_EQ(m[5] , 'A');
}

TEST(IntervalMapTest, VeryComplex)
{
    interval_map<TestKeyType, TestValueType> m('A');
    m.assign(3, 6, 'B');
    m.assign(2, 5, 'C');
    m.assign(4, 7, 'A');

    EXPECT_EQ(m[1] , 'A');
    EXPECT_EQ(m[2] , 'C');
    EXPECT_EQ(m[3] , 'C');
    EXPECT_EQ(m[4] , 'A');
    EXPECT_EQ(m[5] , 'A');
    EXPECT_EQ(m[6] , 'A');
    EXPECT_EQ(m[7] , 'A');
}