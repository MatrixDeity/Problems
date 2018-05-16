/**
    LeetCode_788
    https://leetcode.com/problems/rotated-digits/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int digs[] = { 1, 1, 2, 0, 0, 2, 2, 0, 1, 2 };
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            int num = i;
            int flag = 1;
            while (num > 0) {
                flag *= digs[num % 10];
                num /= 10;
            }
            res += flag >= 2;
        }
        return res;
    }
};

int main() {
    return 0;
}
