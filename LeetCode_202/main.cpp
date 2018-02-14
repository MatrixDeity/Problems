/**
    LeetCode_202
    https://leetcode.com/problems/happy-number/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        while (n > 6) {
            int k = 0;
            while (n != 0) {
                int d = n % 10;
                k += d * d;
                n /= 10;
            }
            n = k;
        }
        return n == 1;
    }
};

int main() {
    return 0;
}
