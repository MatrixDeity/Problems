#include <cstdio>
#include <algorithm>

const int N = 50;
const int M = 8;
const int K = 50;

bool marks[N][M];
int field[N][M];
int currPos[2];
int n, m, k, ans(0), curr;

enum {NONE, CUBE, RECT1, RECT2, RECT3, RECT4, ANGLE1, ANGLE2, ANGLE3, ANGLE4} currType;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &field[i][j]);

    while (k > 0)
    {
        curr = -999;
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < m - 1; ++j)
            {
                currPos[0] = i; currPos[1] = j;
                if (!marks[i][j] && !marks[i + 1][j] && !marks[i][j + 1] && !marks[i + 1][j+1] &&
                    curr < field[i][j] + field[i + 1][j] + field[i][j + 1] + field[i + 1][j + 1])
                {
                    curr = field[i][j] + field[i + 1][j] + field[i][j + 1] + field[i + 1][j + 1];
                    currType = CUBE;
                }

                if (!marks[i][j] && !marks[i + 1][j] && curr < field[i][j] + field[i + 1][j])
                {
                    curr = field[i][j] + field[i + 1][j];
                    currType = RECT1;
                }
                if (!marks[i][j] && !marks[i][j + 1] && curr < field[i][j] + field[i][j + 1])
                {
                    curr = field[i][j] + field[i][j + 1];
                    currType = RECT2;
                }
                if (!marks[i][j + 1] && !marks[i + 1][j + 1] && curr < field[i][j + 1] + field[i + 1][j + 1])
                {
                    curr = field[i][j + 1] + field[i + 1][j + 1];
                    currType = RECT3;
                }
                if (!marks[i + 1][j] && !marks[i + 1][j + 1] && curr < field[i + 1][j] + field[i + 1][j + 1])
                {
                    curr = field[i + 1][j] + field[i + 1][j + 1];
                    currType = RECT4;
                }

                if (!marks[i][j] && !marks[i + 1][j] && !marks[i][j + 1] && curr < field[i][j] + field[i + 1][j] + field[i][j + 1])
                {
                    curr = field[i][j] + field[i + 1][j] + field[i][j + 1];
                    currType = ANGLE1;
                }
                if (!marks[i][j] && !marks[i][j + 1] && !marks[i + 1][j + 1] && curr < field[i][j] + field[i][j + 1] + field[i + 1][j + 1])
                {
                    curr = field[i][j] + field[i][j + 1] + field[i + 1][j + 1];
                    currType = ANGLE2;
                }
                if (!marks[i][j + 1] && !marks[i + 1][j + 1] && !marks[i + 1][j] && curr < field[i][j + 1] + field[i + 1][j + 1] + field[i + 1][j])
                {
                    curr = field[i][j + 1] + field[i + 1][j + 1] + field[i + 1][j];
                    currType = ANGLE3;
                }
                if (!marks[i + 1][j] && !marks[i + 1][j + 1] && !marks[i][j] && curr < field[i + 1][j] + field[i + 1][j + 1] + field[i][j])
                {
                    curr = field[i + 1][j] + field[i + 1][j + 1] + field[i][j];
                    currType = ANGLE4;
                }
            }

        int i = currPos[0], j = currPos[1];
        switch (currType)
        {
        case CUBE:
            marks[i][j] = marks[i + 1][j] = marks[i][j + 1] = marks[i + 1][j+1] = true;
            break;
        case RECT1:
            marks[i][j] = marks[i + 1][j] = true;
            break;
        case RECT2:
            marks[i][j] = marks[i][j + 1] = true;
            break;
        case RECT3:
            marks[i][j + 1] = marks[i + 1][j + 1] = true;
            break;
        case RECT4:
            marks[i + 1][j] = marks[i + 1][j + 1] = true;
            break;
        case ANGLE1:
            marks[i][j] = marks[i + 1][j] = marks[i][j + 1] = true;
            break;
        case ANGLE2:
            marks[i][j] = marks[i][j + 1] = marks[i + 1][j + 1] = true;
            break;
        case ANGLE3:
            marks[i][j + 1] = marks[i + 1][j + 1] = marks[i + 1][j] = true;
            break;
        case ANGLE4:
            marks[i + 1][j] = marks[i + 1][j + 1] = marks[i][j] = true;
            break;
        default:
            break;
        }
        ans += curr;
        --k;
    }

    printf("%d", ans);
    return 0;
}
