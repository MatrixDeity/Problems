/**
    LeetCode_830
    https://leetcode.com/problems/positions-of-large-groups/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int n = S.size();
        for (int i = 0; i < n; ++i) {
            int cnt = 1;
            int beg = i;
            while (i < n - 1 && S[i] == S[i + 1]) {
                ++i, ++cnt;
            }
            if (cnt >= 3) {
                res.push_back({ beg, i });
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
