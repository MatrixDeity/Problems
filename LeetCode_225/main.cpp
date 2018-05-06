/**
    LeetCode_225
    https://leetcode.com/problems/implement-stack-using-queues/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};

int main() {
    return 0;
}
