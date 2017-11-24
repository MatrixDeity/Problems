/**
    LeetCode_3
    https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int res = 0;
        for (size_t i = 0, j = 0; i < s.size() && j < s.size();) {
            if (us.find(s[j]) != us.end()) {
                us.erase(s[i++]);
            } else {
                us.insert(s[j++]);
                res = max((int) us.size(), res);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
