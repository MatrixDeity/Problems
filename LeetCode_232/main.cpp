/**
    LeetCode_232
    https://leetcode.com/problems/implement-queue-using-stacks/description/
    MatrixDeity, 2018.
*/

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    void push(int x) {
        down.push(x);
    }

    int pop() {
        int res = peek();
        up.pop();
        return res;
    }

    int peek() {
        if (up.empty())
            trans();
        return up.top();
    }

    bool empty() {
        return up.empty() && down.empty();
    }

private:
    stack<int> up;
    stack<int> down;

    void trans() {
        while (!down.empty()) {
            up.push(down.top());
            down.pop();
        }
    }
};

int main() {
    return 0;
}
