/**
    LeetCode_521
    https://leetcode.com/problems/longest-uncommon-subsequence-i/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a != b ? max(a.size(), b.size()) : -1;
    }
};

int main() {
    return 0;
}
