/**
    Timus_1296
    http://acm.timus.ru/problem.aspx?space=1&num=1296
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

ll getMaxPosSum(const vector<int>& vec) {
    ll sum(0LL), res(0LL);
    for (int item : vec) {
        sum = max((ll) item, sum + item);
        res = max(sum, res);
    }
    return res > 0LL ? res : 0LL;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& item : vec)
        cin >> item;
    cout << getMaxPosSum(vec);
    return 0;
}
