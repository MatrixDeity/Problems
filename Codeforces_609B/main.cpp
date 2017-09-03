#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, ans(0);
    cin >> n >> m;
    vector<int> vec(m);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++vec[a - 1];
    }
    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j < m; ++j)
            ans += vec[i] * vec[j];
    cout << ans;
    return 0;
}
