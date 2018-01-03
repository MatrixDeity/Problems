/**
    LeetCode_258
    https://leetcode.com/problems/add-digits/description/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num / 10 == 0)
            return num;
        int res = 0;
        while (num != 0) {
            res += num % 10;
            num /= 10;
        }
        return addDigits(res);
    }
};

int main() {
    return 0;
}
