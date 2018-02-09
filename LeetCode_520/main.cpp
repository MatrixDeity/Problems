/**
    LeetCode_520
    https://leetcode.com/problems/detect-capital/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = count_if(word.begin(), word.end(), ::isupper);
        return cap == 1 && isupper(word[0]) || cap == word.size() || cap == 0;
    }
};

int main() {
    return 0;
}
