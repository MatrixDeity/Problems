/**
    LeetCode_500
    https://leetcode.com/problems/keyboard-row/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_set<char> usets[3] = {
            { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' },
            { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' },
            { 'z', 'x', 'c', 'v', 'b', 'n', 'm' }
        };
        for (auto& str : words) {
            for (auto& us : usets) {
                bool flag = true;
                for (auto c : str) {
                    c = tolower(c);
                    if (us.find(c) == us.end()) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res.push_back(str);
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
