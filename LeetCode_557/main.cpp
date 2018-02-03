/**
    LeetCode_557
    https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        int n = (int) s.size();
        while (i < n) {
            if (j == n || s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
            ++j;
        }
        return s;
    }
};

int main() {
    return 0;
}
