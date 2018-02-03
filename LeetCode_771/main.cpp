/**
    LeetCode_771
    https://leetcode.com/problems/jewels-and-stones/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_set<char> us(J.begin(), J.end());
        for (auto c : S) {
            if (us.find(c) != us.end())
                ++res;
        }
        return res;
    }
};

int main() {
    return 0;
}
