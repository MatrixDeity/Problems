/**
    LeetCode_342
    https://leetcode.com/problems/power-of-four/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return fmod(log10(num) / log10(4.0), 1.0) == 0.0;
    }
};

int main() {
    return 0;
}
