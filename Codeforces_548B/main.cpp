/**
    Codeforces_548B
    http://codeforces.com/contest/548/problem/B
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> field(n, vector<int>(m));
    vector<int> cnts(n);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
            if (field[i][j] == 0) {
                cnts[i] = max(cnts[i], cnt);
                cnt = 0;
            } else {
                ++cnt;
            }
        }
        cnts[i] = max(cnts[i], cnt);
    }
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        field[r][c] = !field[r][c];
        cnts[r] = 0;
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (field[r][j] == 0) {
                cnts[r] = max(cnts[r], cnt);
                cnt = 0;
            } else {
                ++cnt;
            }
        }
        cnts[r] = max(cnts[r], cnt);
        int ans = -1;
        for (int item : cnts) {
            ans = max(ans, item);
        }
        cout << ans << endl;
    }
    return 0;
}
