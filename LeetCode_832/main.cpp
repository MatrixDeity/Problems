/**
    LeetCode_832
    https://leetcode.com/problems/flipping-an-image/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& row : A) {
            reverse(row.begin(), row.end());
            transform(row.begin(), row.end(), row.begin(), [] (int a) { return 1 - a; });
        }
        return A;
    }
};

int main() {
    return 0;
}
