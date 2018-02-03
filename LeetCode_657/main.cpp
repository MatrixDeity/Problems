/**
    LeetCode_657
    https://leetcode.com/problems/judge-route-circle/description/
    MatrixDeity, 2018.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int vert = 0, hor = 0;
        for (auto c : moves) {
            vert += (c == 'U') - (c == 'D');
            hor += (c == 'R') - (c == 'L');
        }
        return vert == 0 && hor == 0;
    }
};

int main() {
    return 0;
}
