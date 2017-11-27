/**
    LeetCode_8
    https://leetcode.com/problems/string-to-integer-atoi/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int n = (int) str.size();
        long long res = 0;
        int sign = 0;
        int i = 0;
        while (isspace(str[i]) && i < n)
            ++i;
        for (; i < n; ++i) {
            if (isspace(str[i]) || isalpha(str[i]))
                return sign * res;
            if (str[i] == '-' || str[i] == '+') {
                if (sign == 0)
                    sign = str[i] == '+' ? 1 : -1;
                else
                    return sign * res;
            } else if (isdigit(str[i])) {
                if (sign == 0)
                    sign = 1;
                res = res * 10 + int(str[i] - '0');
                if (res * sign >= INT_MAX)
                    return INT_MAX;
                if (res * sign <= INT_MIN)
                    return INT_MIN;
            }
        }
        return (int) res * sign;
    }
};

int main() {
    return 0;
}
