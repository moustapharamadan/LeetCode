#pragma once

#include <vector>
#include <stack>
#include <array>

namespace LEETCODE_0901 {

    //class StockSpanner {
    //public:
    //    StockSpanner() :
    //        m_prices(),
    //        m_spanner(),
    //        m_s()
    //    {}

    //    int next(int price)
    //    {
    //        int index = m_prices.size();
    //        m_prices.push_back(price);
    //        m_spanner.push_back(1);
    //        while (!m_s.empty() && m_prices[m_s.top()] <= price)
    //        {
    //            m_spanner[index] += m_spanner[m_s.top()];
    //            m_s.pop();
    //        }
    //        m_s.push(index);
    //        return m_spanner[index];
    //    }

    //private:
    //    std::vector<int> m_prices;
    //    std::vector<int> m_spanner;
    //    std::stack<int> m_s;
    //};

    //class StockSpanner {
    //public:
    //    StockSpanner():
    //        m_index(),
    //        m_spanner(),
    //        m_s()
    //    {}

    //    int next(int price) 
    //    {
    //        m_spanner.push_back(1);
    //        while (!m_s.empty() && m_s.top().second <= price)
    //        {
    //            m_spanner[m_index] += m_spanner[m_s.top().first];
    //            m_s.pop();
    //        }
    //        m_s.push({ m_index, price });
    //        return m_spanner[m_index++];
    //    }

    //private:
    //    size_t m_index;
    //    std::vector<int> m_spanner;
    //    std::stack<std::pair<int, int>> m_s;
    //};

    class StockSpanner {
    public:
        StockSpanner() :
            m_s()
        {}

        int next(int price)
        {
            int count = 1;
            while (!m_s.empty() && m_s.top().first <= price)
            {
                count += m_s.top().second;
                m_s.pop();
            }
            m_s.push({ price, count });
            return m_s.top().second;
        }

    private:
        std::stack<std::pair<int, int>> m_s;
    };
}