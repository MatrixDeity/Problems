/**
    LeetCode_338
    https://leetcode.com/problems/counting-bits/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for (int i = 1; i <= num; ++i)
            res[i] = res[i & (i - 1)] + 1;
        return res;
    }
};

int main() {
    return 0;
}
