/**
    Codeforces_816A
    http://codeforces.com/contest/816/problem/A
    MatrixDeity, 2017.
*/

#include <cstdio>

using namespace std;

int main() {
    int h, m, ans(0);
    scanf("%d:%d", &h, &m);
    while (h != (m / 10 + (m % 10) * 10)) {
        ++m;
        h = (h + m / 60) % 24;
        m %= 60;
        ++ans;
    }
    printf("%d", ans);
    return 0;
}
