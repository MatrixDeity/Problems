/**
    LeetCode_732
    https://leetcode.com/problems/my-calendar-iii/
    MatrixDeity, 2022.
*/

#include <map>

using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {}

    int book(int start, int end) {
        ++storage[start];
        --storage[end];

        int res = 0;
        int cur = 0;
        for (const auto& [key, val] : storage) {
            cur += val;
            res = max(res, cur);
        }
        return res;
    }

private:
    map<int, int> storage;
};
