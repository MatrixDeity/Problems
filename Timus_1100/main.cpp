/**
    Timus_1100
    http://acm.timus.ru/problem.aspx?space=1&num=1100
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vec(n);
    for (auto& item : vec) {
        cin >> item.first >> item.second;
    }
    stable_sort(vec.begin(), vec.end(), [] (const pair<ll, ll>& a, const pair<ll, ll>& b) { return a.second > b.second; });
    for (auto& item : vec) {
        cout << item.first << ' ' << item.second << endl;
    }
    return 0;
}
