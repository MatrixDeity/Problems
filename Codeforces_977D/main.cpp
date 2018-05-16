/**
    Codeforces_977D
    http://codeforces.com/contest/977/problem/D
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> vec(n);
    vector<bool> visited(n);
    vector<ll> ans;
    for (auto& item : vec) {
        cin >> item;
    }
    function<void(int)> dfs = [&] (int v) {
        ans.push_back(vec[v]);
        visited[v] = true;
        for (int u = 0; u < n; ++u) {
            if (!visited[u] && (vec[v] * 2 == vec[u] || vec[v] == vec[u] * 3)) {
                dfs(u);
            }
        }
    };
    for (int v = 0; v < n; ++v) {
        ans.clear();
        fill(visited.begin(), visited.end(), false);
        dfs(v);
        if (ans.size() == n) {
            break;
        }
    }
    for (auto& item : ans) {
        cout << item << ' ';
    }
    return 0;
}
