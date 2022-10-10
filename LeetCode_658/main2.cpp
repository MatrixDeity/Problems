/**
    LeetCode_658
    https://leetcode.com/problems/find-k-closest-elements/
    MatrixDeity, 2022.
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1;
        while (r - l >= k) {
            if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                --r;
            } else {
                ++l;
            }
        }
        vector<int> res;
        res.reserve(k);
        for (; l <= r; ++l) {
            res.push_back(arr[l]);
        }
        return res;
    }
};
