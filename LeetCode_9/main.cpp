/**
    LeetCode_9
    https://leetcode.com/problems/palindrome-number/description/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        long long dir = x;
        long long rev = 0;
        while (x != 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return dir == rev;
    }
};

int main() {
    return 0;
}
