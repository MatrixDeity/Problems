/**
    LeetCode_67
    https://leetcode.com/problems/add-binary/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        string ans;
        int r = 0;
        for (;i >= 0 || j >= 0 || r > 0; --i, --j) {
            int x = i >= 0 ? int(a[i] - '0') : 0;
            int y = j >= 0 ? int(b[j] - '0') : 0;
            ans.push_back(char(x ^ y ^ r + '0'));
            r = int(x + y + r > 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    return 0;
}
