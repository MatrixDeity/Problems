/**
    Codeforces_580C
    http://codeforces.com/contest/580/problem/C
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> cats;
int n, m, ans(0);

void countLeaves(int root, int parent, int nCats) {
    if (cats[root] == 1)
        ++nCats;
    else
        nCats = 0;
    if (nCats > m)
        return;
    if (tree[root].size() > 1 || root == 1) {
        for (int node : tree[root]) {
            if (node != parent)
                countLeaves(node, root, nCats);
        }
    } else
        ++ans;
}

int main() {
    cin >> n >> m;
    tree.resize(n + 1);
    cats.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> cats[i];
    for (int i = 1; i < n; ++i) {
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    countLeaves(1, -1, 0);
    cout << ans;
    return 0;
}
