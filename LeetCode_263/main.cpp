/**
    LeetCode_263
    https://leetcode.com/problems/ugly-number/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num == 0)
            return false;
        while (num != 1) {
            if (num % 5 == 0)
                num /= 5;
            else if (num % 3 == 0)
                num /= 3;
            else if (num % 2 == 0)
                num /= 2;
            else
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
