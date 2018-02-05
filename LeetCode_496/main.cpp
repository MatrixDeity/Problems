/**
    LeetCode_496
    https://leetcode.com/problems/next-greater-element-i/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> st;
        unordered_map<int, int> um;
        vector<int> res;
        for (auto item : nums) {
            while (!st.empty() && st.top() < item) {
                um[st.top()] = item;
                st.pop();
            }
            um[item] = -1;
            st.push(item);
        }
        for (auto item : findNums) {
            res.push_back(um[item]);
        }
        return res;
    }
};

int main() {
    return 0;
}
