/**
    LeetCode_791
    https://leetcode.com/problems/custom-sort-string/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> um;
        int n = S.size();
        for (int i = 0; i < n; ++i) {
            um[S[i]] = n - i;
        }
        sort(T.begin(), T.end(), [&um] (char a, char b) {
            return um[a] > um[b];
        });
        return T;
    }
};

int main() {
    return 0;
}
