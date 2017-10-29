/**
    Codeforces_767A
    http://codeforces.com/contest/767/problem/A
    MatrixDeity, 2017.
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> snks;
    int n;
    cin >> n;
    int cnt = n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        snks.push(a);
        while (!snks.empty() && snks.top() == cnt) {
            cout << snks.top() << ' ';
            snks.pop();
            --cnt;
        }
        cout << endl;
    }
    return 0;
}
