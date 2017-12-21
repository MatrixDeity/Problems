/**
    LeetCode_69
    https://leetcode.com/problems/sqrtx/description/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long a = x;
        while (a * a > x) {
            a = (a + x / a) / 2;
        }
        return a;
    }
};

int main() {
    return 0;
}
