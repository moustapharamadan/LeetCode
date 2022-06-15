#pragma once
#include <list>
#include <unordered_map>

namespace LEETCODE_0146 {
    class LRUCache {
    public:
        LRUCache(int capacity) :
            m_capacity(capacity),
            m_values(),
            m_map()
        {
        }

        int get(int key) 
        {
            KeyValueMapNode it = m_map.find(key);
            if (m_map.end() == it)
            {
                return -1;
            }

            m_values.push_front(*it->second);
            m_values.erase(it->second);
            m_map[key] = m_values.begin();
            return m_values.front().second;
        }

        void put(int key, int value) 
        {
            KeyValueMapNode it = m_map.find(key);
            if (m_map.end() != it)
            {
                m_values.erase(it->second);
            }
            else if (m_values.size() == m_capacity)
            {
                m_map.erase(m_values.back().first);
                m_values.pop_back();
            }

            m_values.push_front(KeyValue(key, value));
            m_map[key] = m_values.begin();
        }
    private:
        typedef std::pair<int, int> KeyValue;
        typedef std::list<KeyValue>::iterator KeyValueNode;
        typedef std::unordered_map<int, KeyValueNode>::iterator KeyValueMapNode;
        size_t m_capacity;
        std::list<KeyValue> m_values;
        std::unordered_map<int, KeyValueNode> m_map;
    };
}