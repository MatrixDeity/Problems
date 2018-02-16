/**
    LeetCode_415
    https://leetcode.com/problems/add-strings/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int n = num1.size(), m = num2.size();
        int i = n - 1, j = m - 1, rem = 0;
        while (i >= 0 || j >= 0 || rem != 0) {
            int a = i >= 0 ? num1[i--] - '0' : 0;
            int b = j >= 0 ? num2[j--] - '0' : 0;
            int val = a + b + rem;
            res.push_back(char(val % 10) + '0');
            rem = val / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}
