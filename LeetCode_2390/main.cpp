/**
    LeetCode_2390
    https://leetcode.com/problems/removing-stars-from-a-string/
    MatrixDeity, 2023.
*/

#include <string>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int j = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*') {
                s[j++] = s[i];
            } else {
                --j;
            }
        }

        return s.substr(0, j);
    }
};
