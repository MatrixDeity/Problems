/**
    LeetCode_438
    https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> res;
        if (n < m) {
            return res;
        }
        vector<int> um1(26), um2(26);
        for (int i = 0; i < m; ++i) {
            ++um1[s[i] - 'a'];
            ++um2[p[i] - 'a'];
        }
        if (um1 == um2) {
            res.push_back(0);
        }
        for (int i = 0; i + m < n; ++i) {
            ++um1[s[i + m] - 'a'];
            --um1[s[i] - 'a'];
            if (um1 == um2) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
