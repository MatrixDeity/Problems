/**
    LeetCode_1431
    https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
    MatrixDeity, 2023.
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = 0;
        vector<bool> res;
        res.reserve(candies.size());

        for (auto num : candies) {
            maxCandy = max(num, maxCandy);
        }

        for (auto num : candies) {
            res.push_back(num + extraCandies >= maxCandy);
        }

        return res;
    }
};
