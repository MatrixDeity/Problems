/**
    Codeforces_714A
    http://codeforces.com/contest/714/problem/A
    MatrixDeity, 2016.
*/

#include <iostream>

using namespace std;

long long l1, r1, l2, r2, k, ans;

int main()
{
    cin >> l1 >> r1 >> l2 >> r2 >> k;

    if (r1 < l2)
    {
        cout << 0 << endl;
        return 0;
    }

    if (l1 > l2)
    {
        swap(l1, l2);
        swap(r1, r2);
    }
    ans = r1 - l2 + 1;
    if (k >= l2 && k <= r1)
        --ans;

    cout << ans << endl;
    return 0;
}
