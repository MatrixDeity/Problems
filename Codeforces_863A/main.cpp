/**
    Codeforces_863A
    http://codeforces.com/contest/863/problem/A
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

int isPalid(int num) {
    int n = num;
    int rev = 0;
    while (n != 0) {
        rev *= 10;
        rev += n % 10;
        n /= 10;
    }
    return num == rev;
}

int main() {
    int n;
    cin >> n;
    while (n != 0 && n % 10 == 0)
        n /= 10;
    cout << (isPalid(n) ? "YES" : "NO");
    return 0;
}
