/**
    LeetCode_20
    https://leetcode.com/problems/valid-parentheses/description/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else if (!st.empty() && valid(st.top(), c))
                st.pop();
            else
                return false;
        }
        return st.empty();
    }

    bool valid(char l, char r) {
        return l == '(' && r == ')' ||
               l == '[' && r == ']' ||
               l == '{' && r == '}';
    }
};

int main() {
    return 0;
}
