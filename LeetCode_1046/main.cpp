/**
    LeetCode_1046
    https://leetcode.com/problems/last-stone-weight/
    MatrixDeity, 2022.
*/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        while (q.size() > 1) {
            int rock1 = q.top();
            q.pop();
            int rock2 = q.top();
            q.pop();
            int newRock = abs(rock1 - rock2);
            q.push(newRock);
        }
        return q.top();
    }
};
