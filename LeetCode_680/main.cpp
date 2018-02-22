/**
    LeetCode_680
    https://leetcode.com/problems/valid-palindrome-ii/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <functional>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        auto check = [&s] (int i, int j) {
            while (i < j) {
                if (s[i] != s[j])
                    return false;
                ++i, --j;
            }
            return true;
        };
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return check(i, j - 1) || check(i + 1, j);
            ++i, --j;
        }
        return true;
    }
};

int main() {
    return 0;
}
