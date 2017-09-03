#include <cstdio>

using namespace std;

int n, a, counter(0);

int main()
{
    scanf("%d", &n);
    if (n == 1)
    {
        scanf("%d", &a);
        printf("%s", a == n ? "YES" : "NO");
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        counter += a;
    }

    printf("%s", counter == n - 1 ? "YES" : "NO");
    return 0;
}
