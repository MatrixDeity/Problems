/**
    LeetCode_383
    https://leetcode.com/problems/ransom-note/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> um;
        for (auto c : magazine) {
            ++um[c];
        }
        for (auto c : ransomNote) {
            --um[c];
            if (um[c] < 0)
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
