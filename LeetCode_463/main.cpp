/**
    LeetCode_463
    https://leetcode.com/problems/island-perimeter/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        int m = (int) grid.front().size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    res += j > 0 ? 1 - grid[i][j - 1] : 1;
                    res += j < m - 1 ? 1 - grid[i][j + 1] : 1;
                    res += i > 0 ? 1 - grid[i - 1][j] : 1;
                    res += i < n - 1 ? 1 - grid[i + 1][j] : 1;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
