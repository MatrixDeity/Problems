/**
    LeetCode_66
    https://leetcode.com/problems/plus-one/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), rem = 1;
        int i = n - 1;
        while (i >= 0) {
            int val = digits[i] + rem;
            digits[i] = val % 10;
            rem = val / 10;
            --i;
        }
        if (rem != 0) {
            digits[0] = rem;
            digits.push_back(0);
        }
        return digits;
    }
};

int main() {
    return 0;
}
