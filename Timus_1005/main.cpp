/**
    Timus_1005
    http://acm.timus.ru/problem.aspx?space=1&num=1005&locale=ru
    MatrixDeity, 2017
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

const int N = 20;

vector<int> vec(N), sums;

void checkRocks(int subSum, int index, int n) {
    sums.push_back(subSum);
    for (int i = index + 1; i < n; i++)
        checkRocks(subSum + vec[i], i, n);
}

int main() {
    int n;
    int sum(0), min(INT_MAX), ans(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        sum += vec[i];
    }
    for (int i = 0; i < n; i++)
        checkRocks(vec[i], i, n);
    int half = sum / 2;
    for (int item : sums) {
        if (abs(half - item) < abs(half - min))
            min = item;
    }
    ans = abs(sum - 2 * min);

    cout << ans;
    return 0;
}
