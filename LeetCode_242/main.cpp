/**
    LeetCode_242
    https://leetcode.com/problems/valid-anagram/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um;
        int n = s.size();
        for (auto c : s) {
            ++um[c];
        }
        for (auto c : t) {
            --um[c];
        }
        for (auto& p : um) {
            if (p.second != 0)
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
