/**
ЗАДАНИЕ:
  Masha has recently bought a cleaner robot, it can clean a floor without anybody's assistance.
  Schematically Masha's room is a rectangle, consisting of w*h square cells of size 1*1. Each cell of the room is either empty (represented
  by character '.'), or occupied by furniture (represented by character '*').
  A cleaner robot fully occupies one free cell. Also the robot has a current direction (one of four options), we will say that it looks in this direction.
  The algorithm for the robot to move and clean the floor in the room is as follows:
    - clean the current cell which a cleaner robot is in;
    - if the side-adjacent cell in the direction where the robot is looking exists and is empty, move to it and go to step 1;
    - otherwise turn 90 degrees clockwise (to the right relative to its current direction) and move to step 2.
  The cleaner robot will follow this algorithm until Masha switches it off.
  You know the position of furniture in Masha's room, the initial position and the direction of the cleaner robot. Can you calculate the total area
  of the room that the robot will clean if it works infinitely?

ВВОД:
  The first line of the input contains two integers, w and h (1 <= w, h <= 10) - the sizes of Masha's room.
  Next w lines contain h characters each - the description of the room. If a cell of a room is empty, then the corresponding character equals '.'.
  If a cell of a room is occupied by furniture, then the corresponding character equals '*'. If a cell has the robot, then it is empty, and the
  corresponding character in the input equals 'U', 'R', 'D' or 'L', where the letter represents the direction of the cleaner robot. Letter 'U' shows that
  the robot is looking up according to the scheme of the room, letter 'R' means it is looking to the right, letter 'D' means it is looking down and letter
  'L' means it is looking to the left.
  It is guaranteed that in the given w lines letter 'U', 'R', 'D' or 'L' occurs exactly once. The cell where the robot initially stands is empty (does not
  have any furniture).

ВЫВОД:
  In the first line of the output print a single integer - the total area of the room that the robot will clean if it works infinitely.
*/

#include <iostream>
#include <mem.h>

using namespace std;

const int N = 100;

int main() {
    bool checked[N][N][4];
    char field[N][N];
    int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
    int w, h, x, y, dir, ans(0);
    memset(checked, false, N*N*4);
    cin >> w >> h;
    for (int i = 0; i < w; ++i)
        cin >> field[i];

    bool flag = false;
    for (int i = 0; i < w && !flag; ++i)
        for (int j = 0; j < h && !flag; ++j)
        {
            switch (field[i][j])
            {
            case 'U':
                dir = 0;
                flag = true;
                break;
            case 'R':
                dir = 1;
                flag = true;
                break;
            case 'D':
                dir = 2;
                flag = true;
                break;
            case 'L':
                dir = 3;
                flag = true;
                break;
            }
            if (flag)
                x = j, y = i;
        }
    while (!checked[y][x][dir])
    {
        checked[y][x][dir] = true;
        int nx(x + dx[dir]), ny(y + dy[dir]);
        if (nx >= 0 && ny >= 0 && nx < h && ny < w && field[ny][nx] != '*')
            x = nx, y = ny;
        else
            dir = (dir + 1) % 4;
    }

    for (int i = 0; i < w; ++i)
        for (int j = 0; j < h; ++j)
            if (checked[i][j][0] || checked[i][j][1] || checked[i][j][2] || checked[i][j][3])
                ++ans;

    cout << ans;
    return 0;
}
