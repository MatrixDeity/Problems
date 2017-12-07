/**
    LeetCode_39
    https://leetcode.com/problems/combination-sum/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        function<void(int, int)> impl = [&impl, &res, &candidates, &tmp] (int it, int target) mutable {
            if (target < 0)
                return;
            if (target == 0) {
                res.push_back(tmp);
                return;
            }
            for (int i = it; i < (int) candidates.size(); ++i) {
                int a = candidates[i];
                tmp.push_back(a);
                impl(i, target - a);
                tmp.pop_back();
            }
        };
        impl(0, target);
        return res;
    }
};

int main() {
    return 0;
}
