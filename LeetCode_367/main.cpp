/**
    LeetCode_367
    https://leetcode.com/problems/valid-perfect-square/discuss/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    using ll = long long;
    bool isPerfectSquare(int num) {
        ll a = num;
        while (a * a > num) {
            a = (a + num / a) / 2;
        }
        return a * a == num;
    }
};

int main() {
    return 0;
}
