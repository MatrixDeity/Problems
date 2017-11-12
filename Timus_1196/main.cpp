/**
    Timus_1196
    http://acm.timus.ru/problem.aspx?space=1&num=1196
    MatrixDeity, 2017.
*/

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n, ans(0);
    unordered_set<int> us;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        us.insert(a);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (us.find(a) != us.end())
            ++ans;
    }
    cout << ans;
    return 0;
}
