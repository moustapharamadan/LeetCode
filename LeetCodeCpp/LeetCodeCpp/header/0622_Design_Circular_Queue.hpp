#pragma once
#include <vector>

namespace LEETCODE_0622 {
    class MyCircularQueue {
    public:
        MyCircularQueue(int k) :
            m_data(std::vector<int>(k, 0)),
            m_head(0),
            m_tail(-1),
            m_size(0)
        {
        }

        bool enQueue(int value) {
            if (isFull())
                return false;

            m_tail = (m_tail + 1) % m_data.size();
            m_data[m_tail] = value;
            ++m_size;
            return true;
        }

        bool deQueue() {
            if (isEmpty())
                return false;

            m_head = (m_head + 1) % m_data.size();
            --m_size;
            return true;
        }

        int Front() {
            if (isEmpty())
                return -1;
            return m_data[m_head];
        }

        int Rear() {
            if (isEmpty())
                return -1;
            return m_data[m_tail];
        }

        bool isEmpty() {
            return 0 == m_size;
        }

        bool isFull() {
            return m_data.size() == m_size;
        }
    private:
        std::vector<int> m_data;
        int m_head;
        int m_tail;
        size_t m_size;
    };
}
