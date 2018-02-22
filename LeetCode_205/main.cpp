/**
    LeetCode_205
    https://leetcode.com/problems/isomorphic-strings/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> ums;
        unordered_map<char, int> umt;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (ums[s[i]] != umt[t[i]])
                return false;
            ums[s[i]] = umt[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
    return 0;
}
