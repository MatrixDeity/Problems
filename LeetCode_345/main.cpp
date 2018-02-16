/**
    LeetCode_345
    https://leetcode.com/problems/reverse-vowels-of-a-string/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        unordered_set<char> us = { 'e', 'E', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'a', 'A' };
        while (i < j) {
            while (us.count(s[i]) == 0)
                ++i;
            while (us.count(s[j]) == 0)
                --j;
            swap(s[i], s[j]);
        }
        return s;
    }
};

int main() {
    return 0;
}
