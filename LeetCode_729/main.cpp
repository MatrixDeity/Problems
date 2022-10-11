/**
    LeetCode_729
    https://leetcode.com/problems/my-calendar-i/
    MatrixDeity, 2022.
*/

#include <set>
#include <map>

using namespace std;

class MyCalendar {
public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = storage.upper_bound({ start, end });
        if (it != storage.end() && it->second < end) {
            return false;
        }
        storage.insert({ end, start });
        return true;
    }

private:
    set<pair<int, int>> storage;
};
