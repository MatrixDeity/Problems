#include <iostream>

using namespace std;

const int N = 2e5;
long long arr[N];
long long n, ans, minA(3e9), maxLen(0), len;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        minA = min(minA, arr[i]);
    }
    ans = n * minA;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == minA)
        {
            len = 0;
            for (int j = 1; j < n; ++j)
            {
                if (arr[(i + j) % n] == arr[i])
                    break;
                ++len;
            }
            maxLen = max(maxLen, len);
        }
    }
    cout << ans + maxLen;
    return 0;
}
