/**
    LeetCode_70
    https://leetcode.com/problems/climbing-stairs/description/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1)
            return 1;

        int a = 1, b = 2;
        for (int i = 2; i < n; ++i) {
            int tmp = a;
            a = b;
            b = tmp + a;
        }
        return b;
    }
};

int main() {
    return 0;
}
