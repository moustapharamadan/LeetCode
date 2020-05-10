#pragma once
#include <list>
#include <unordered_map>
#include <algorithm>

class LFUCache {
public:
    LFUCache(int capacity):
        m_capacity(capacity)
    {
    }

    int get(int key) 
    {
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator>::iterator hashTable_it = m_hashTable.find(key);
        if (hashTable_it != m_hashTable.end())
        {
            std::list<std::pair<int, int>>::iterator data_it = hashTable_it->second;    //get the data pair iterator
            std::unordered_map<int, int>::iterator frequency_it = m_freqency.find(key);     //get the frequency iterator
            int currentFreq = frequency_it->second;     // get the frequency of the key
            m_data[currentFreq + 1].splice(m_data[currentFreq + 1].begin(), m_data[currentFreq], data_it);  //tramsfer the data_it(the pointer) from the list of data for the current freq, to the list of data for the above freq 
                                                                                                            // and put it at the beginning of the new list (similar to LRUCache)
            if (m_data[currentFreq].size() == 0) {      // if the list of data for the current freq is empty => erase the list
                m_data.erase(currentFreq);
            }
            ++frequency_it->second;     //increase the frequency of current data
            return data_it->second;     //return the value
        }
        return -1;
    }

    void put(int key, int value)
    {
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator>::iterator hashTable_it = m_hashTable.find(key);
        if (hashTable_it != m_hashTable.end()) 
        {
            std::list<std::pair<int, int>>::iterator data_it = hashTable_it->second;    //get the data pair iterator
            std::unordered_map<int, int>::iterator frequency_it = m_freqency.find(key);     //get the frequency iterator
            int currentFreq = frequency_it->second;     // get the frequency of the key
            m_data[currentFreq+1].splice(m_data[currentFreq+1].begin(),m_data[currentFreq],data_it);    //tramsfer the data_it(the pointer) from the list of data for the current freq, to the list of data for the above freq 
                                                                                                        // and put it at the beginning of the new list (similar to LRUCache)
            data_it->second = value;        // change the existing value
            if (m_data[currentFreq].size() == 0) {      // if the list of data for the current freq is empty => erase the list
                m_data.erase(currentFreq);
            }
            ++frequency_it->second;     //increament the freq
        }
        else
        {
            if (m_capacity > 0) {   //push new value if the size is greater than zero
                if (m_freqency.size() == m_capacity)        //if the size exceed the capacity we should delete the LFU Data 
                {
                    std::map<int, std::list<std::pair<int, int>>>::iterator LFUDataList_it = m_data.begin();    //Get an iterator of the list of data with lowest frequency 
                    std::list<std::pair<int, int>>& LFUDataList = LFUDataList_it->second;   //get a reference of the list of data with the lowest freq
                    m_hashTable.erase(LFUDataList.back().first);
                    m_freqency.erase(LFUDataList.back().first);
                    LFUDataList.pop_back();     //erase the last element of the Least Frequent Used data
                                                //we push_front the recently used element, so that the least recently used element will be at the end of the list
                    if (LFUDataList.size() == 0) {  // if the list of data for the least freq is empty => erase the list
                        m_data.erase(LFUDataList_it->first);
                    }
                }
                m_data[1].push_front({ key,value });    //push front the pair to the list of frequency equal to 1
                m_hashTable[key] = m_data[1].begin();   //add the iterator of the newly pushed element
                ++m_freqency[key];  // m_frequency[key]=1;
            }
        }
    }
private:
    int m_capacity;
    std::map<int, std::list<std::pair<int, int>>> m_data; //map of data with the same frequency, ie key:frequency, value: list of pair 
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_hashTable; // unorderedmap of key and value pointer(iterator) to the pair data 
    std::unordered_map<int, int> m_freqency; //unorderedmap of key and frequency 
};
