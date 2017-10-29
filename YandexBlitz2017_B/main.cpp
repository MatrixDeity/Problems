#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

const int N = 9999999;

int sumDigits(int n) {
    int ans(0);
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

bool formula(int k, int& res) { // true - if result is integer number
    int s = sumDigits(k);
    double dRes = (3.0 * k) / (s * s);
    bool ans = dRes == trunc(dRes);
    if (ans)
        res = (int) floor(dRes);
    return ans;
}

int main() {
    unordered_set<int> labels;
    for (int i = 1; i <= N; ++i) {
        int f;
        if (formula(i, f))
            labels.insert(f);
    }
    for (int i = 1; i <= N; ++i) {
        if(labels.find(i) == labels.end()) {
            cout << i;
            break;
        }
    }
    return 0;
}
