#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;
const int M = 2e5;

long long n, m, u, v, ans(0);

vector<long long> arr[N];
long long maxSeq[N];

int main()
{
    cin >> n >> m;
    fill(maxSeq, maxSeq + n, 0);
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        --u;
        --v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            if (i >= arr[i][j])
                maxSeq[i] = max(maxSeq[i], maxSeq[ arr[i][j] ] + 1);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        ++maxSeq[i];
        ans = max(ans, maxSeq[i] * arr[i].size());
    }
    cout << ans;
    return 0;
}
