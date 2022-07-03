#pragma once

#include<map>
#include<unordered_map>
#include<list>

namespace LEETCODE_0460 {

    class LFUCache {
    public:
        LFUCache(int capacity):
            m_size(0),
            m_capacity(capacity),
            m_keyValueAndFreq(),
            m_freqKeys(),
            m_keyListIterator()
        {}

        int get(int key) 
        {
            if (!m_keyValueAndFreq.count(key))
                return -1;

            updateFrequency(key);
            return m_keyValueAndFreq[key].first;
        }

        void put(int key, int value) 
        {
            if (m_capacity <= 0)
                return;

            if (m_keyValueAndFreq.count(key))
            {
                m_keyValueAndFreq[key].first = value;
                updateFrequency(key);
                return;
            }

            if (m_size >= m_capacity)
            {
                auto it = m_freqKeys.begin();
                int keyToRemove = it->second.back();
                it->second.pop_back();
                if (it->second.empty())
                    m_freqKeys.erase(it);
                m_keyListIterator.erase(keyToRemove);
                m_keyValueAndFreq.erase(keyToRemove);
                --m_size;
            }

            ++m_size;
            m_keyValueAndFreq[key] = { value, 1 };
            m_freqKeys[1].push_front(key);
            m_keyListIterator[key] = m_freqKeys[1].begin();
        }
    private:
        void updateFrequency(int key)
        {
            int& frequency = m_keyValueAndFreq[key].second;
            m_freqKeys[frequency].erase(m_keyListIterator[key]);
            if (m_freqKeys[frequency].empty())
                m_freqKeys.erase(frequency);

            ++frequency;
            m_freqKeys[frequency].push_front(key);
            m_keyListIterator[key] = m_freqKeys[frequency].begin();
        }
    private:
        int m_size;
        int m_capacity;
        std::unordered_map<int, std::pair<int, int>> m_keyValueAndFreq;
        std::map<int, std::list<int>> m_freqKeys;
        std::unordered_map<int, std::list<int>::iterator> m_keyListIterator;
    };
}