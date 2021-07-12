#pragma once
#include <unordered_map>
#include <list>

//146. LRU Cache
class LRUCache {
public:
    LRUCache(int capacity) :
        m_capacity(capacity)
    {
    }

    int get(int key)
    {
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator>::iterator hashTable_it = m_hashTable.find(key);
        if (hashTable_it != m_hashTable.end()) {
            std::list<std::pair<int, int>>::iterator data_it = hashTable_it->second;
            m_data.splice(m_data.begin(), m_data, data_it); //transfers the element pointed by data_it from m_data into the beginning of m_data.
            return data_it->second; //return the value
        }
        return -1;
    }

    void put(int key, int value) {
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator>::iterator hashTable_it = m_hashTable.find(key);
        if (hashTable_it != m_hashTable.end())
        {
            std::list<std::pair<int, int>>::iterator data_it = hashTable_it->second;
            m_data.splice(m_data.begin(), m_data, data_it); //transfers the element pointed by data_it from m_data into the beginning of m_data
            data_it->second = value; //change the value pointed by the iterator
        }
        else {
            if (m_data.size() >= m_capacity) {
                m_hashTable.erase(m_data.back().first); //erase the least recently used data iterator from the table
                m_data.pop_back();  //erase the least recently used data
                //PS: erase the least recently used element will before insert the new one will optimize run time 
                //    because the erase will need to search for the element before removing it (ie less data for search)
            }
            m_data.push_front({ key, value }); //it will emplace the pair, to avoid creating the pair and copying it
            m_hashTable[key] = m_data.begin();  //add the new key and iterator to the table
        }
    }
protected:
    int m_capacity;
    std::list<std::pair<int, int>> m_data;  //data container of key, value 
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_hashTable; //stores reference to the values
};
