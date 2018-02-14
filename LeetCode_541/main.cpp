/**
    LeetCode_541
    https://leetcode.com/problems/reverse-string-ii/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size(), step = 2 * k;
        for (int pos = 0; pos < n; pos += step) {
            int i = pos, j = pos + k <= n ? pos + k - 1 : n - 1;
            while (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};

int main() {
    return 0;
}
