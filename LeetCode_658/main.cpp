/**
    LeetCode_658
    https://leetcode.com/problems/find-k-closest-elements/
    MatrixDeity, 2022.
*/

#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        ans.reserve(k);
        priority_queue<pair<int, int>> pq;
        for (int num : arr) {
            pq.push({ abs(x - num), num });
            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
