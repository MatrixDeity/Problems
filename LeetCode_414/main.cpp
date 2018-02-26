/**
    LeetCode_414
    https://leetcode.com/problems/third-maximum-number/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (auto num : nums) {
            s.insert(num);
            if (s.size() > 3)
                s.erase(s.begin());
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};

int main() {
    return 0;
}
