#include "../pch.h"
#include "../header/0622_Design_Circular_Queue.hpp"

using namespace LEETCODE_0622;

class MyCircularQueueTest : public ::testing::Test {
};
TEST_F(MyCircularQueueTest, Test1)
{
	MyCircularQueue myCircularQueue(3);
	EXPECT_TRUE(myCircularQueue.enQueue(1));
	EXPECT_TRUE(myCircularQueue.enQueue(2));
	EXPECT_TRUE(myCircularQueue.enQueue(3));
	EXPECT_FALSE(myCircularQueue.enQueue(4));
	EXPECT_EQ(myCircularQueue.Rear(),3);
	EXPECT_TRUE(myCircularQueue.isFull());
	EXPECT_TRUE(myCircularQueue.deQueue());
	EXPECT_TRUE(myCircularQueue.enQueue(4));
	EXPECT_EQ(myCircularQueue.Rear(),4);
}

TEST_F(MyCircularQueueTest, Test2)
{
	MyCircularQueue myCircularQueue(3);
	EXPECT_TRUE(myCircularQueue.enQueue(2));
	EXPECT_EQ(myCircularQueue.Rear(),2);
	EXPECT_EQ(myCircularQueue.Front(),2);
	EXPECT_TRUE(myCircularQueue.deQueue());
	EXPECT_EQ(myCircularQueue.Front(), -1);
	EXPECT_FALSE(myCircularQueue.deQueue());
	EXPECT_EQ(myCircularQueue.Front(), -1);
	EXPECT_TRUE(myCircularQueue.enQueue(4));
	EXPECT_TRUE(myCircularQueue.enQueue(2));
	EXPECT_TRUE(myCircularQueue.enQueue(2));
	EXPECT_FALSE(myCircularQueue.enQueue(3));
}

TEST_F(MyCircularQueueTest, Test3)
{
	MyCircularQueue myCircularQueue(2);
	EXPECT_TRUE(myCircularQueue.enQueue(4));
	EXPECT_EQ(myCircularQueue.Rear(), 4);
	EXPECT_TRUE(myCircularQueue.enQueue(9));
	EXPECT_TRUE(myCircularQueue.deQueue());
	EXPECT_EQ(myCircularQueue.Front(), 9);
	EXPECT_TRUE(myCircularQueue.deQueue());
	EXPECT_FALSE(myCircularQueue.deQueue());
	EXPECT_TRUE(myCircularQueue.isEmpty());
	EXPECT_FALSE(myCircularQueue.deQueue());
	EXPECT_TRUE(myCircularQueue.enQueue(6));
	EXPECT_TRUE(myCircularQueue.enQueue(4));
}
