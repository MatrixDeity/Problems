/**
    Codeforces_616A
    http://codeforces.com/contest/616/problem/A
    MatrixDeity, 2017.
*/

#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 5;

char strA[N];
char strB[N];

int main() {
    scanf("%s%s", strA, strB);
    char* a = strA;
    char* b = strB;
    int n = strlen(a);
    int m = strlen(b);
    while (n > 1 && *a == '0') {
        ++a;
        --n;
    }
    while (m > 1 && *b == '0') {
        ++b;
        --m;
    }
    if (n > m)
        printf(">");
    else if (n < m)
        printf("<");
    else {
        while (*a != '\0')
            if (*a > *b) {
                printf(">");
                return 0;
            }
            else if (*a < *b) {
                printf("<");
                return 0;
            }
            else {
                ++a;
                ++b;
            }
            printf("=");
    }
    return 0;
}
