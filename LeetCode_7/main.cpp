/**
    LeetCode_7
    https://leetcode.com/problems/reverse-integer/description/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res(0);
        while (x != 0) {
            int tmp = res * 10 + x % 10;
            if (tmp / 10 != res)
                return 0;
            res = tmp;
            x /= 10;
        }
        return res;
    }
};

int main() {
    return 0;
}
