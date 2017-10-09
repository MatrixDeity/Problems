/**
    Codeforces_839A
    http://codeforces.com/contest/839/problem/A
    MatrixDeity, 2017.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k, ans(0), rem(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a;
    	cin >> a;
    	rem += a;
    	k -= min(rem, 8);
        rem -= min(rem, 8);
        ++ans;
        if (k <= 0)
        	break;
    }
    cout << (k > 0 ? -1 : ans);
	return 0;
}
