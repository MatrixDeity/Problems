/**
    LeetCode_1768
    https://leetcode.com/problems/merge-strings-alternately/
    MatrixDeity, 2023.
*/

#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        auto n = word1.size(), m = word2.size();
        res.reserve(n + m);

        size_t i = 0;
        for (; i < n && i < m; ++i) {
            res.push_back(word1[i]);
            res.push_back(word2[i]);
        }

        for (; i < n; ++i) {
            res.push_back(word1[i]);
        }

        for (; i < m; ++i) {
            res.push_back(word2[i]);
        }

        return res;
    }
};
