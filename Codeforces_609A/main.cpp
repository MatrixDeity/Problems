#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    int n, m, ans(0);
    vector<int> vec;
    cin >> n >> m;
    vec.reserve(n);
    copy_n(istream_iterator<int>(cin), n, back_inserter(vec));
    sort(vec.begin(), vec.end(), greater<int>());
    for (int i = 0; i < n && m > 0; ++i) {
        m -= vec[i];
        ++ans;
    }
    cout << ans;
    return 0;
}
