/**
    Codeforces_710A
    http://codeforces.com/contest/710/problem/A
    MatrixDeity, 2016.
*/

#include <iostream>

using namespace std;

int main()
{
    char c;
    int d;
    cin >> c >> d;
    if (c == 'a' && d == 1 ||
        c == 'a' && d == 8 ||
        c == 'h' && d == 1 ||
        c == 'h' && d == 8)
    {
        cout << 3;
        return 0;
    }
    if (c == 'a' || c == 'h' || d == 1 || d == 8)
    {
        cout << 5;
        return 0;
    }
    cout << 8;
    return 0;
}
