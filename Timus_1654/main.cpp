/**
    Timus_1654
    http://acm.timus.ru/problem.aspx?space=1&num=1654
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    string str, ans;
    cin >> str;
    stack<char> stk;
    for (char chr : str) {
        if (!stk.empty() && stk.top() == chr)
            stk.pop();
        else
            stk.push(chr);
    }
    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
