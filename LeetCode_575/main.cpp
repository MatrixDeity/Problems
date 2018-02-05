/**
    LeetCode_575
    https://leetcode.com/problems/distribute-candies/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> us(candies.begin(), candies.end());
        return min(candies.size() / 2, us.size());
    }
};

int main() {
    return 0;
}
