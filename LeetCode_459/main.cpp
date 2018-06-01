/**
    LeetCode_459
    https://leetcode.com/problems/repeated-substring-pattern/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string tmp = (s + s).substr(1, s.size() * 2 - 2);
        return tmp.find(s) != string::npos;
    }
};

int main() {
    return 0;
}
