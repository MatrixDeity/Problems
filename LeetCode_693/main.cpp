/**
    LeetCode_693
    https://leetcode.com/problems/binary-number-with-alternating-bits/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int b;
        do {
            b = n % 2;
            n /= 2;
            if ((n & 1 ^ b == 0)
                return false;
        } while (n != 0);
        return true;
    }
};

int main() {
    return 0;
}
