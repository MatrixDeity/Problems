/**
    LeetCode_434
    https://leetcode.com/problems/number-of-segments-in-a-string/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            cnt += !isspace(s[i]) && (i + 1 == n || isspace(s[i + 1]));
        }
        return cnt;
    }
};

int main() {
    return 0;
}
