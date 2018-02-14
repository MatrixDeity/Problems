/**
    LeetCode_409
    https://leetcode.com/problems/longest-palindrome/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> um;
        int res = 0;
        for (auto c : s) {
            ++um[c];
        }
        for (auto& p : um) {
            int v = p.second;
            res += v % 2 == 0 || res % 2 == 0 ? v : v - 1;
        }
        return res;
    }
};

int main() {
    return 0;
}
