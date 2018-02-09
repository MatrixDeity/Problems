/**
    LeetCode_695
    https://leetcode.com/problems/max-area-of-island/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = (int) grid.size(), m = (int) grid.front().size();
        function<int(int, int)> impl = [&impl, &grid, n, m] (int i, int j) {
            if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
                return 0;

            grid[i][j] = 0;
            return 1 + impl(i - 1, j) + impl(i + 1, j) + impl(i, j - 1) + impl(i, j + 1);
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res = max(impl(i, j), res);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
