#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int inf(0), n, ans(-1), num;
    cin >> n;
    num = n;
    vector<int> arr(n);
    vector<bool> flags(n, false);
    for (int& x : arr)
        cin >> x;

    while (num > 0)
    {
        ++ans;
        if (ans % 2 == 0)
            for (int i = 0; i < n; ++i)
            {
                if (arr[i] <= inf && !flags[i])
                {
                    ++inf;
                    flags[i] = true;
                    --num;
                }
            }
        else
            for (int i = n-1; i >=0; --i)
            {
                if (arr[i] <= inf && !flags[i])
                {
                    ++inf;
                    flags[i] = true;
                    --num;
                }
            }
    }

    cout << ans;
    return 0;
}
