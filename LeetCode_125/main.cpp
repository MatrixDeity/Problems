/**
    LeetCode_125
    https://leetcode.com/problems/valid-palindrome/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = (int) s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i]))
                ++i;
            while (i < j && !isalnum(s[j]))
                --j;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            ++i;
            --j;
        }
        return true;
    }
};

int main() {
    return 0;
}
