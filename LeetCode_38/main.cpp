/**
    LeetCode_38
    https://leetcode.com/problems/count-and-say/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)
            return "";

        string res = "1";
        for (int i = 1; i < n; ++i) {
            string tmp;
            int m = (int) res.size();
            for (int j = 0; j < m;) {
                int cnt = 0;
                char c = res[j];
                while (j < m && res[j] == c) {
                    ++cnt;
                    ++j;
                }
                tmp.append(to_string(cnt) + c);
            }
            res = move(tmp);
        }
        return res;
    }
};

int main() {
    return 0;
}
