/**
    LeetCode_387
    https://leetcode.com/problems/first-unique-character-in-a-string/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> um;
        for (char c : s)
            ++um[c];
        for (int i = 0; i < (int) s.size(); ++i) {
            if (um[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main() {
    return 0;
}
