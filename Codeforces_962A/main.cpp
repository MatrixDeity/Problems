/**
    Codeforces_962A
    http://codeforces.com/contest/962/problem/A
    MatrixDeity, 2018.
*/

#include <iostream>
#include <valarray>

using namespace std;

int main() {
    int n;
    cin >> n;
    valarray<int> arr(n);
    for (auto& item : arr) {
        cin >> item;
    }
    int half = (arr.sum() + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum >= half) {
            cout << i + 1;
            break;
        }
    }
    return 0;
}
