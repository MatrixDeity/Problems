/**
    LeetCode_1528
    https://leetcode.com/problems/shuffle-string/
    MatrixDeity, 2022.
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res = s;
        for (size_t i = 0; i < s.size(); ++i) {
            res[indices[i]] = s[i];
        }
        return res;
    }
};
