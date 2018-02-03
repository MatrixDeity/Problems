/**
    LeetCode_476
    https://leetcode.com/problems/number-complement/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (num & mask)
            mask <<= 1;
        return ~num & ~mask;
    }
};

int main() {
    return 0;
}
