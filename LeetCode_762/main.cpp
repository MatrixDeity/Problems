/**
    LeetCode_762
    https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <unordered_set>
#include <bitset>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> us = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        int res = 0;
        for (int i = L; i <= R; ++i) {
            bitset<32> bs(i);
            res += us.count(bs.count());
        }
        return res;
    }
};

int main() {
    return 0;
}
