/**
    Timus_1082
    http://acm.timus.ru/problem.aspx?space=1&num=1082
    MatrixDeity, 2017.
*/

// That's not the solution!
/*
    #include <stdio.h>

    const long N = 2;

    long c;
    long A[N];

    long P(long l, long r) {
        long x = A[l],
             i = l - 1,
             j = r + 1,
             t;
        while (1) {
            do {
                --j;
                ++c;
            } while (A[j] > x);
            do {
                ++i;
                ++c;
            } while(A[i] < x);
            if (i < j) {
                t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
            else
                return j;
        }
    }

    void Q(long l, long r) {
        long n;
        if (l < r) {
            n = P(l, r);
            Q(l, n);
            Q(n + 1, r);
        }
    }

    int main(void) {
        c = 0;
        for (long i = 0; i < N; ++i)
            scanf("%ld", &A[i]);
        Q(0, N - 1);
        if (c == (N * N + 3 * N - 4) / 2)
            printf("Vasilisa");
        else
            printf("Koshey");
        return 0;
    }
*/

// That's the solution! If someone could name it so...
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << i << ' ';
    }
    return 0;
}
