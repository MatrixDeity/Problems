/**
    LeetCode_567
    https://leetcode.com/problems/permutation-in-string/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), m = s1.size();
        unordered_map<char, int> um;
        for (char c : s1) {
            ++um[c];
        }
        for (int i = 0, j = 0; j < n; ++j) {
            char c = s2[j];
            --um[c];
            if (um[c] < 0) {
                while (um[c] < 0) {
                    ++um[s2[i]];
                    ++i;
                }
            } else if (j - i + 1 == m) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
