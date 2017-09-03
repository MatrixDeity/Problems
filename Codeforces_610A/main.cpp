#include <iostream>

using namespace std;

int n, ans(0);

int main()
{
    cin >> n;
    if (n % 2 || n < 6)
    {
        cout << ans;
        return 0;
    }
    ans = n / 4;
    if (n % 4 == 0)
        --ans;

    cout << ans;
    return 0;
}
