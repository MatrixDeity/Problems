/**
    LeetCode_504
    https://leetcode.com/problems/base-7/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";

        int n = abs(num);
        string res;
        int base = 7;
        while (n != 0) {
            char dig = n % base + '0';
            res.push_back(dig);
            n /= base;
        }
        if (num < 0)
            res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}
