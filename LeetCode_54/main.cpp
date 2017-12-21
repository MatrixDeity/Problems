/**
    LeetCode_54
    https://leetcode.com/problems/spiral-matrix/discuss/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;;

        int m = (int) matrix.size();
        int n = (int) matrix[0].size();
        res.reserve(m * n);
        int t = 0, l = 0, r = n - 1, b = m - 1;
        while (t <= b && l <= r) {
            for (int i = l; i <= r; ++i)
                res.push_back(matrix[t][i]);
            ++t;
            for (int i = t; i <= b; ++i)
                res.push_back(matrix[i][r]);
            --r;
            if (t > b || l > r)
                break;
            for (int i = r; i >= l; --i)
                res.push_back(matrix[b][i]);
            --b;
            for (int i = b; i >= t; --i)
                res.push_back(matrix[i][l]);
            ++l;
        }
        return res;
    }
};

int main() {
    return 0;
}
