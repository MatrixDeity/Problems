/**
    LeetCode_766
    https://leetcode.com/problems/toeplitz-matrix/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return true;

        int n = (int) matrix.size();
        int m = (int) matrix.front().size();
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
