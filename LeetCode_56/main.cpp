/**
    LeetCode_56
    https://leetcode.com/problems/merge-intervals/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty())
            return res;

        int n = (int) intervals.size();
        auto pred = [] (Interval& l, Interval& r) {
            return l.start < r.start;
        };
        sort(intervals.begin(), intervals.end(), pred);
        res.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            if (res.back().end >= intervals[i].start)
                res.back().end = max(intervals[i].end, res.back().end);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};

int main() {
    return 0;
}
