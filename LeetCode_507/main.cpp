/**
    LeetCode_507
    https://leetcode.com/problems/perfect-number/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1)
            return false;
        int sum = 1;
        for (int d = 2; d * d <= num; ++d) {
            if (num % d == 0) {
                sum += d * d != num ? d + num / d : d;
            }
        }
        return sum == num;
    }
};

int main() {
    return 0;
}
