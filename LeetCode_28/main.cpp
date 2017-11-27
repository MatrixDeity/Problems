/**
    LeetCode_28
    https://leetcode.com/problems/implement-strstr/description/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = (int) haystack.size();
        int m = (int) needle.size();
        for (int i = 0; i < n - m + 1; ++i) {
            int j = 0;
            while (i + j < n && j < m && haystack[i + j] == needle[j]) {
                ++j;
            }
            if (j == m)
                return i;
        }
        return -1;
    }
};

int main() {
    return 0;
}
