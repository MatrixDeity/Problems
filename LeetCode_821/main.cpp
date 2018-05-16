/**
    LeetCode_821
    https://leetcode.com/problems/shortest-distance-to-a-character/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> res(n, n);
        int let = -n;
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) {
                let = i;
            }
            res[i] = min(abs(i - let), res[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (S[i] == C) {
                let = i;
            }
            res[i] = min(abs(i - let), res[i]);
        }
        return res;
    }
};

int main() {
    return 0;
}
