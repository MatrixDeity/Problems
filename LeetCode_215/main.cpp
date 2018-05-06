/**
    LeetCode_215
    https://leetcode.com/problems/kth-largest-element-in-an-array/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> ms;
        for (auto item : nums) {
            ms.insert(item);
            if (ms.size() > k)
                ms.erase(ms.begin());
        }
        return *ms.begin();
    }
};

int main() {
    return 0;
}
