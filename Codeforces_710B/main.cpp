/**
    Codeforces_710B
    http://codeforces.com/contest/710/problem/B
    MatrixDeity, 2016.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    size_t n;
    cin >> n;
    vector<int> vec(n);
    copy_n(istream_iterator<int>(cin), n, vec.begin());

    sort(vec.begin(), vec.end());

    cout << (n % 2 == 0 ? vec[n / 2 - 1] : vec[n / 2]);
    return 0;
}
