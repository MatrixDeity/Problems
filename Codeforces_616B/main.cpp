/**
    Codeforces_616B
    http://codeforces.com/contest/616/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m, ans(INT_MAX);
    vector<vector<int>> costs;
    cin >> n >> m;
    costs.resize(n);
    int minVal = 0;
    int maxRow = 0;
    for (int i = 0; i < n; ++i) {
        int mv = INT_MAX;
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            costs[i].push_back(a);
            if (a < mv)
                mv = a;
        }
        if (mv > minVal) {
            maxRow = i;
            minVal = mv;
        }
    }
    for (int j = 0; j < m; ++j) {
        int a = costs[maxRow][j];
        if (a < ans)
            ans = a;
    }
    cout << ans;
    return 0;
}
