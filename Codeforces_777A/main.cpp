/**
    Codeforces_777A
    http://codeforces.com/contest/777/problem/A
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

int main() {
    int n, x;
    bool arr[3] = {};
    cin >> n >> x;
    arr[x] = true;
    n %= 6;
    for (int i = n; i >= 1; --i) {
        if (i % 2 == 1) {
            swap(arr[0], arr[1]);
        } else {
            swap(arr[1], arr[2]);
        }
    }
    for (int i = 0; i < 3; ++i)
        if (arr[i])
            cout << i;
    return 0;
}
