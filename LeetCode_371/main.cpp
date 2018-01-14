/**
    LeetCode_371
    https://leetcode.com/problems/sum-of-two-integers/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int tmp = a ^ b;
            b = (a & b) << 1;
            a = tmp;
        }
        return a;
    }
};

int main() {
    return 0;
}
