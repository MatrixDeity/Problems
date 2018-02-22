/**
    LeetCode_278
    https://leetcode.com/problems/first-bad-version/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (!isBadVersion(m))
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
};

int main() {
    return 0;
}
