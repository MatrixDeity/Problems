/**
    LeetCode_191
    https://leetcode.com/problems/number-of-1-bits/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    using uint = uint32_t;

    int hammingWeight(uint n) {
        int res = 0;
        uint ts = sizeof(n) * 8;
        for (uint i = 0; i < ts; ++i)
            res += (n >> i) & 1;
        return res;
    }
};

int main() {
    return 0;
}
