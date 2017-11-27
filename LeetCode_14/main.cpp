/**
    LeetCode_14
    https://leetcode.com/problems/longest-common-prefix/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string pref = strs[0];
        for (size_t i = 1; i < strs.size(); ++i) {
            while (strs[i].find(pref) != 0) {
                pref.resize(pref.size() - 1);
                if (pref.empty())
                    return "";
            }
        }
        return pref;
    }
};

int main() {
    return 0;
}
