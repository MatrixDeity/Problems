/**
    LeetCode_401
    https://leetcode.com/problems/binary-watch/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                bitset<10> bs((h << 6) + m);
                if (bs.count() == num) {
                    string s = to_string(h) + (m < 10 ? ":0" : ":") + to_string(m);
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
