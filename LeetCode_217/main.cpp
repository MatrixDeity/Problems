/**
    LeetCode_217
    https://leetcode.com/problems/contains-duplicate/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (auto num : nums) {
            if (us.find(num) == us.end())
                us.insert(num);
            else
                return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
