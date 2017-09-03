/**
    Timus_1026
    http://acm.timus.ru/problem.aspx?space=1&num=1026
    MatrixDeity, 2016.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5;

int arr[N];
char dummy[5];
int n, k, a;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d\n", &arr[i]);
    sort(arr, arr + n);
    gets(dummy);

    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &a);
        printf("%d\n", arr[a - 1]);
    }

    return 0;
}
