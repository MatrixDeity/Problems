/**
    Timus_1864
    http://acm.timus.ru/problem.aspx?space=1&num=1864
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using ld = long double;

int main() {
    int n;
    ld sum(0.0L);
    cin >> n;
    vector<ld> vec(n);
    for (auto& item : vec) {
        cin >> item;
        sum += item;
    }
    ld part = sum / (n + 1);
    ld rem = 0.0L;
    for (auto item : vec)
        if (item > part)
            rem += item - part;
    for (auto item : vec)
        cout << (item > part ? floor(100.0L * (item - part) / rem) : 0.0L) << ' ';
    return 0;
}
