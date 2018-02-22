/**
    LeetCode_290
    https://leetcode.com/problems/word-pattern/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> ump;
        unordered_map<string, int> ums;
        stringstream ss(str);
        int n = pattern.size(), i = 0;
        for (string tmp; ss >> tmp; ++i) {
            if (i == n || ump[pattern[i]] != ums[tmp])
                return false;
            ump[pattern[i]] = ums[tmp] = i + 1;
        }
        return i == n;
    }
};

int main() {
    return 0;
}
