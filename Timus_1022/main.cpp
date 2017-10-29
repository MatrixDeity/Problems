/**
    Timus_1022
    http://acm.timus.ru/problem.aspx?space=1&num=1022
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Graph = vector<vector<int>>;

void dfs(Graph& graph, int from, vector<bool>& used, vector<int>& anses) {
    if (used[from])
        return;

    used[from] = true;
    for (int node : graph[from])
        dfs(graph, node, used, anses);
    anses.push_back(from);
}

int main() {
    int n;
    cin >> n;
    Graph graph(n + 1);
    vector<bool> used(n + 1);
    vector<int> anses;
    for (int i = 1; i <= n; ++i) {
        int a;
        while (cin >> a && a != 0) {
            graph[i].push_back(a);
        }
    }
    for (int i = 1; i <= n; ++i)
        dfs(graph, i, used, anses);
    for (auto it = anses.rbegin(); it != anses.rend(); ++it)
        cout << *it << ' ';
    return 0;
}
