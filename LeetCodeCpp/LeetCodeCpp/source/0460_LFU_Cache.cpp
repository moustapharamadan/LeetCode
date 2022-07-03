#include "../pch.h"
#include "../header/0460_LFU_Cache.hpp"

using LFUCache = LEETCODE_0460::LFUCache;

TEST(LFU_Cache, capacity_two)
{
    LFUCache lfu(2);
    lfu.put(1, 1);                  // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);                  // cache=[2,1], cnt(2)=1, cnt(1)=1
    EXPECT_EQ(1, lfu.get(1));       // return 1
                                    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);                  // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                                    // cache=[3,1], cnt(3)=1, cnt(1)=2
    EXPECT_EQ(-1, lfu.get(2));      // return -1 (not found)
    EXPECT_EQ(3, lfu.get(3));       // return 3
                                    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);                  // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                                    // cache=[4,3], cnt(4)=1, cnt(3)=2
    EXPECT_EQ(-1, lfu.get(1));      // return -1 (not found)
    EXPECT_EQ(3, lfu.get(3));       // return 3
                                    // cache=[3,4], cnt(4)=1, cnt(3)=3
    EXPECT_EQ(4, lfu.get(4));       // return 4
                                    // cache=[4,3], cnt(4)=2, cnt(3)=3
}

TEST(LFU_Cache, test2)
{
    LFUCache lfu(2);
    lfu.put(3, 1);           
    lfu.put(2, 2);           
    lfu.put(2, 2);           
    lfu.put(4, 4);           
    EXPECT_EQ(2, lfu.get(2));
}