/**
    LeetCode_461
    https://leetcode.com/problems/hamming-distance/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int ts = sizeof(n) * 8;
        int res = 0;
        for (int i = 0; i < ts; ++i)
            res += (n >> i) & 1;
        return res;
    }
};

int main() {
    return 0;
}
