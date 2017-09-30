/**
    Codeforces_864D
    http://codeforces.com/contest/864/problem/D
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, ans(0);
    cin >> n;
    vector<int> cnts(n + 1);
    vector<int> vec(n);
    for (int& item : vec) {
        cin >> item;
        ++cnts[item];
    }
    vector<bool> used(n + 1);
    int ptrNeed = 1;
    for (int& item : vec) {
        if (cnts[item] > 1) {
            while (cnts[ptrNeed] > 0)
                ++ptrNeed;
            if (item > ptrNeed || used[item]) {
                --cnts[item];
                item = ptrNeed;
                ++cnts[ptrNeed];
                ++ans;
            } else
                used[item] = true;
        }
    }
    cout << ans << endl;
    for (int item : vec)
        cout << item << ' ';
    return 0;
}
