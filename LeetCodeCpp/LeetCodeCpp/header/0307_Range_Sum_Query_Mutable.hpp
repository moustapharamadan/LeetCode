#pragma once
#include <vector>
#include <numeric>

namespace LEETCODE_0307
{
namespace sqrtDecomposition {

class NumArray {
    std::vector<int>& m_array;
    std::vector<int> m_sqrtDecomposition;
    int m_decomposition;
public:
    NumArray(std::vector<int>& nums) :
        m_array(nums)
    {
        m_decomposition = ceil(sqrt(nums.size()));
        int arraySize = m_array.size();
        for (int i = 0; i < m_decomposition; ++i)
        {
            int beginIndex = i * m_decomposition;
            if (arraySize < beginIndex)
                return;
            int endIndex = beginIndex + m_decomposition;
            int sum = std::accumulate(m_array.begin() + beginIndex, endIndex < arraySize ? m_array.begin() + endIndex : m_array.end(), 0);
            m_sqrtDecomposition.push_back(sum);
        }
    }

    void update(int index, int val) {
        m_sqrtDecomposition[index / m_decomposition] += val - m_array[index];
        m_array[index] = val;
    }

    int sumRange(int left, int right) {
        int endLeftBlock = left - left % m_decomposition + m_decomposition;
        int startRightBlock = right - right % m_decomposition;
        if (endLeftBlock >= startRightBlock)
            return std::accumulate(m_array.begin() + left, m_array.begin() + right + 1, 0);

        int leftSum = std::accumulate(m_array.begin() + left, m_array.begin() + endLeftBlock, 0);
        int rightSum = std::accumulate(m_array.begin() + startRightBlock, m_array.begin() + right + 1, 0);
        int midSum = std::accumulate(m_sqrtDecomposition.begin() + endLeftBlock / m_decomposition, m_sqrtDecomposition.begin() + startRightBlock / m_decomposition, 0);
        return leftSum + midSum + rightSum;
    }
};

}

namespace segmentTree {

class NumArray {
    std::vector<int>& m_array;
    std::vector<int> m_tree;
public:
    NumArray(std::vector<int>& nums) :
        m_array(nums)
    {
        int arraySize = m_array.size();
        m_tree = std::vector<int>(arraySize, 0);
        m_tree.insert(m_tree.end(), m_array.begin(), m_array.end());
        for (int i = arraySize - 1; i > 0; --i)
        {
            m_tree[i] = m_tree[2 * i] + m_tree[2 * i + 1];
        }
    }

    void update(int index, int val) {
        int variation = val - m_array[index];
        m_array[index] = val;
        int position = index + m_array.size();
        do {
            m_tree[position] += variation;
            position /= 2;
        } while (position);
    }

    int sumRange(int left, int right) {
        left += m_array.size();
        right += m_array.size();

        int sum = 0;
        while (left <= right)
        {
            if ((left % 2) == 1) {
                sum += m_tree[left];
                ++left;
            }

            if ((right % 2) == 0) {
                sum += m_tree[right];
                --right;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

}

}
