/**
    YandexInternship2017_A
    https://contest.yandex.ru/contest/4085/problems/A/
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

const int N = 101;

int field[2][N][N];
int counter[N][N];

void inputField(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[0][i][j];
        }
    }
}

void printCounter(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << counter[i][j] << ' ';
        }
        cout << endl;
    }
}

void updateStatus(int n, int m, int now) {
    now %= 2;
    int last = (now + 1) % 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int l = (j - 1 < 0 ? 0 : field[last][i][j - 1]);
            int r = (j + 1 >= m ? 0 : field[last][i][j + 1]);
            int t = (i - 1 < 0 ? 0 : field[last][i - 1][j]);
            int b = (i + 1 >= n ? 0 : field[last][i + 1][j]);
            int cnt = (l == 2) + (r == 2) + (t == 2) + (b == 2);
            if (cnt > 1)
                field[now][i][j] = 2;
            else if (l > 1 || r > 1 || t > 1 || b > 1)
                field[now][i][j] = 3;
            else
                field[now][i][j] = 1;
            counter[i][j] += field[now][i][j] != field[last][i][j];
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    inputField(n, m);
    for (int i = 1; i <= k; ++i) {
        updateStatus(n, m, i);
    }
    printCounter(n, m);
    return 0;
}
