/**
    LeetCode_58
    https://leetcode.com/problems/length-of-last-word/description/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = (int) s.size();
        int i = n - 1, j = n - 1;
        while (j >= 0 && s[j] == ' ')
            --j;
        i = j;
        while (i >= 0 && s[i] != ' ')
            --i;
        return j - i;
    }
};

int main() {
    return 0;
}
