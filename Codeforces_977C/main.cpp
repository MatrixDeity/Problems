/**
    Codeforces_977C
    http://codeforces.com/contest/977/problem/C
    MatrixDeity, 2018.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (auto& item : vec) {
        cin >> item;
    }
    sort(vec.begin(), vec.end());
    if (k == 0) {
        cout << (vec[k] > 1 ? 1 : -1);
    } else {
        cout << (vec[k - 1] != vec[k] ? vec[k - 1] : -1);
    }
    return 0;
}
