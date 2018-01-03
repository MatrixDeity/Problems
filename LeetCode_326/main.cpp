/**
    LeetCode_326
    https://leetcode.com/problems/power-of-three/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n) / log10(3.0), 1.0) == 0.0;
    }
};

int main() {
    return 0;
}
