/**
    Codeforces_714B
    http://codeforces.com/contest/714/problem/B
    MatrixDeity, 2016.
*/

#include <iostream>
#include <set>

using namespace std;

set<long long> samples;
long long a, n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        samples.insert(a);
        if (samples.size() > 3)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (samples.size() < 3)
    {
        cout << "YES" << endl;
        return 0;
    }

    int first = *samples.begin();
    int mid = *++samples.begin();
    int last = *--samples.end();
    cout << (last - mid == mid - first ? "YES" : "NO") << endl;
    return 0;
}
