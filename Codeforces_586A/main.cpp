#include <stdio.h>

using namespace std;

const int N = 100;

int main()
{
    int arr[N];
    bool flag = false;
    int n, count(0), ans(0);

    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &arr[i]);

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 1)
        {
            ++ans;
            if (flag && count < 2 && arr[i-1] == 0)
                ++ans;
            count = 0;
            flag = true;
        }
        else if (flag)
            ++count;
    }

    printf("%i", ans);
    return 0;
}
