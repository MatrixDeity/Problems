#include <iostream>
#include <vector>

using namespace std;

const int N = 50;

int main()
{
    int n, vi, hi;
    vector<int> ans;
    ans.reserve(N*N);
    cin >> n;
    vector<bool> v(n, false);
    vector<bool> h(n, false);

    for (int i = 0; i < n*n; ++i)
    {
        cin >> hi >> vi;
        if (!h[hi-1] && !v[vi-1])
        {
            ans.push_back(i+1);
            h[hi-1] = true;
            v[vi-1] = true;
        }
    }

    for (int x : ans)
        cout << x << ' ';
    return 0;
}
