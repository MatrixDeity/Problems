/**
    LeetCode_389
    https://leetcode.com/problems/find-the-difference/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = '\0';
        for (char c : s)
            res ^= c;
        for (char c : t)
            res ^= c;
        return res;
    }
};

int main() {
    return 0;
}
