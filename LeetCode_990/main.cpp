/**
    LeetCode_990
    https://leetcode.com/problems/satisfiability-of-equality-equations/
    MatrixDeity, 2022.
*/

#include <array>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) {
            buff[i] = i;
        }

        for (const auto& str : equations) {
            if (str[1] == '=') {
                buff[find(str[0]-'a')] = find(str[3]-'a');
            }
        }

        for (const auto& str : equations) {
            if (str[1] == '!' && find(str[0]-'a') == find(str[3]-'a')) {
                return false;
            }
        }

        return true;
    }

private:
    int find(int x) {
        if (x == buff[x]) {
            return x;
        }
        return find(buff[x]);
    }

    array<int, 26> buff;
};
