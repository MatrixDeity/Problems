/**
    Timus_1106
    http://acm.timus.ru/problem.aspx?space=1&num=1106
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

using Graph = vector<vector<int>>;

int main() {
    int n;
    cin >> n;
    if (n < 2)
        cout << 0;
    Graph graph(n + 1);
    unordered_set<int> ans;
    vector<int> colors(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        int to;
        while (true) {
            cin >> to;
            if (to == 0)
                break;
            graph[i].push_back(to);
        }
    }
    for (int i = 1; i <= n; ++i) {
        bool flag = true;
        for (int node : graph[i]) {
            flag &= ans.find(node) == ans.end();
        }
        if (flag)
            ans.insert(i);
    }
    cout << ans.size() << endl;
    for (int item : ans)
        cout << item << ' ';
    return 0;
}
