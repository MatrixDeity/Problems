#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100;

bool arr[N];
int n, m, x, a;

int main()
{
    cin >> n >> m;
    fill(arr, arr + m, false);
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        for (int j = 0; j < x; ++j)
        {
            cin >> a;
            arr[a-1] = true;
        }
    }

    for (int i = 0; i < m; ++i)
        if (!arr[i])
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}
