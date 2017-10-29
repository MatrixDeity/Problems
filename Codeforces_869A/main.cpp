/**
    Codeforces_869A
    http://codeforces.com/contest/869/problem/A
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, ans(0);
    cin >> n;
    vector<int> koyomi(n);
    vector<int> karen(n);
    unordered_set<int> us;
    for (int& item : koyomi) {
        cin >> item;
        us.insert(item);
    }
    for (int& item : karen) {
        cin >> item;
        us.insert(item);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = koyomi[i] ^ karen[j];
            if (us.find(x) != us.end())
                ++ans;
        }
    }
    cout << (ans % 2 == 0 ? "Karen" : "Koyomi");
    return 0;
}
