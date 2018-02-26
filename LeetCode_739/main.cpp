/**
    LeetCode_739
    https://leetcode.com/problems/daily-temperatures/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()])
                st.pop();
            res[i] = !st.empty() ? st.top() - i : 0;
            st.push(i);
        }
        return res;
    }
};

int main() {
    return 0;
}
