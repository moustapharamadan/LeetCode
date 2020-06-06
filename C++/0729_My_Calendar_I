#pragma once
#include <vector>
#include <set>

// (s1,e1) (s2,e2)
// to insert an element e2<=s1 or s2>=e1
//In other words e2<=s1, e1<=s2 => end<=rhs.start

//class MyCalendar {
//public:
//    MyCalendar() {
//
//    }
//
//    bool book(int start, int end) {
//        if (start > end) {
//            int temp = start;
//            start = end;
//            end = temp;
//        }
//        for (const std::pair<int, int> p : m_events) {
//            if(! (end <= p.first || start >= p.second) ){
//                return false;
//            }
//        }
//        m_events.push_back(std::pair<int, int>(start, end));
//        return true;
//    }
//private:
//    std::vector<std::pair<int, int>> m_events;
//};

class Booking {
public:
    Booking(const int start, const int end):
        m_start(start),m_end(end)
    {
    }
    bool operator<(const Booking& rhs) const {
        return m_end <= rhs.m_start; 
    }
private:
    int m_start;
    int m_end;
};



class MyCalendar {
public:
    MyCalendar() {

    }
    bool book(int start, int end) {
        return m_events.emplace(start,end).second;
    }
private:
    std::set<Booking> m_events;
};
