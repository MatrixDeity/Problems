/**
    LeetCode_728
    https://leetcode.com/problems/self-dividing-numbers/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        res.reserve(right - left + 1);
        for (int i = left; i <= right; ++i) {
            int n = i;
            while (n != 0) {
                int d = n % 10;
                if (d == 0 || i % d != 0)
                    break;
                n /= 10;
            }
            if (i != 0 && n == 0)
                res.push_back(i);
        }
        return res;
    }
};

int main() {
    return 0;
}
