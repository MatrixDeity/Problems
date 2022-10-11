/**
    LeetCode_729
    https://leetcode.com/problems/my-calendar-i/
    MatrixDeity, 2022.
*/

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> counter;
        for (int num : arr1) {
            ++counter[num];
        }

        auto it1 = arr1.begin();
        for (int num : arr2) {
            auto& val = counter[num];
            while (val > 0) {
                *it1 = num;
                --val;
                ++it1;
            }
        }

        for (auto& [num, val] : counter) {
            while (val > 0) {
                *it1 = num;
                --val;
                ++it1;
            }
        }

        return arr1;
    }
};
