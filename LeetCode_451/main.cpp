/**
    LeetCode_451
    https://leetcode.com/problems/sort-characters-by-frequency/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> um;
        for (char c : s)
            ++um[c];
        auto pred = [&] (char a, char b) {
            return um[a] > um[b] || (um[a] == um[b] && a < b);
        };
        sort(s.begin(), s.end(), pred);
        return s;
    }
};

int main() {
    return 0;
}
