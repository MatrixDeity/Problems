/**
    Codeforces_977F
    http://codeforces.com/contest/977/problem/F
    MatrixDeity, 2018.
*/

#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> vec(n);
    map<int, int> mp;
    int maxLen = 1;
    int last = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
        int a = vec[i];
        int len = mp[a] = mp[a - 1] + 1;
        if (len > maxLen) {
            maxLen = len;
            last = i;
        }
    }
    vector<int> res;
    res.reserve(n);
    res.push_back(last);
    for (int i = last - 1; i >= 0; --i) {
        if (vec[i] == vec[res.back()] - 1) {
            res.push_back(i);
        }
    }
    printf("%d\n", maxLen);
    for (int i = res.size() - 1; i >= 0; --i) {
        printf("%d ", res[i] + 1);
    }
    return 0;
}
