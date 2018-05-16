/**
    Codeforces_977E
    http://codeforces.com/contest/977/problem/E
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<bool> visited(n);
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int f, t;
        cin >> f >> t;
        --f, --t;
        graph[f].push_back(t);
        graph[t].push_back(f);
    }
    bool ok = true;
    function<void(int)> dfs = [&] (int v) {
        if (visited[v]) {
            return;
        }
        visited[v] = true;
        ok &= graph[v].size() == 2;
        for (auto u : graph[v]) {
            dfs(u);
        }
    };
    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            ok = true;
            dfs(v);
            ans += ok;
        }
    }
    cout << ans;
    return 0;
}
