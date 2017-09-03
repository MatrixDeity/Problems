/**
    Timus_1225
    http://acm.timus.ru/problem.aspx?space=1&num=1225
    MatrixDeity, 2015.
 */

#include <cstdio>

using namespace std;

long long n, m1(2), m2(2), m(2);

int main()
{
    scanf("%I64i", &n);
    if (n > 2)
    {
        for (int i = 3; i <= n; ++i)
        {
            m = m1 + m2;
            m1 = m2;
            m2 = m;
        }
    }

    printf("%I64d", m);
    return 0;
}
