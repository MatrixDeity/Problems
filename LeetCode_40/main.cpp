/**
    LeetCode_40
    https://leetcode.com/problems/combination-sum-ii/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        impl(0, target, candidates, tmp, res);
        return res;
    }

private:
    void impl(int it, int target, vector<int>& cand, vector<int>& tmp, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        if (target < 0)
            return;

        for (int i = it; i < (int) cand.size(); ++i) {
            if (i > it && cand[i] == cand[i - 1])
                continue;
            tmp.push_back(cand[i]);
            impl(i + 1, target - cand[i], cand, tmp, res);
            tmp.pop_back();
        }
    }
};

int main() {
    return 0;
}
