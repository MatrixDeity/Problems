#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

using Graph = vector<vector<bool>>;

struct NotBigraph {};

const int RED = 1;
const int BLUE = ~RED;
const int CLEAN = 0;

void paint(Graph& graph, vector<int>& colors) {
    int n = graph.size();
    function<void(int, int)> dfs = [&] (int v, int c) {
        colors[v] = c;
        for (int u = 0; u < n; ++u) {
            if (v != u && graph[v][u]) {
                if (colors[u] == c)
                    throw NotBigraph();
                if (colors[u] == CLEAN) {
                    dfs(u, ~c);
                }
            }
        }
    };
    int c = RED;
    for (int v = 0; v < n; ++v) {
        if (colors[v] == CLEAN) {
            dfs(v, c);
            c = ~c;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph graph(n, vector<bool>(n, true));
    vector<int> colors(n, CLEAN);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        graph[a][b] = graph[b][a] = false;
    }
    try {
        paint(graph, colors);
        printf("%d\n", count(colors.begin(), colors.end(), RED));
        for (int v = 0; v < n; ++v) {
            if (colors[v] == RED) {
                printf("%d ", v + 1);
            }
        }
        printf("\n");
        for (int v = 0; v < n; ++v) {
            if (colors[v] == BLUE) {
                printf("%d ", v + 1);
            }
        }
    } catch (NotBigraph) {
        printf("-1");
    }
    return 0;
}
