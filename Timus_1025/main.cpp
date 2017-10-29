/**
    Timus_1025
    http://acm.timus.ru/problem.aspx?space=1&num=1025
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, ans(0);
    cin >> k;
    vector<int> vec(k);
    for (int& item : vec) {
        cin >> item;
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < k / 2 + 1; ++i) {
        ans += vec[i] / 2 + 1;
    }
    cout << ans;
    return 0;
}
