/**
    LeetCode_155
    https://leetcode.com/problems/min-stack/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {
    }

    void push(int x) {
        if (ms.empty() || ms.top() >= x)
            ms.push(x);
        s.push(x);
    }

    void pop() {
        if (!ms.empty() && ms.top() == s.top())
            ms.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return ms.top();
    }

private:
    stack<int> s;
    stack<int> ms;
};

int main() {
    return 0;
}
