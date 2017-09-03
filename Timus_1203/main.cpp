/**
    Timus_1203
    http://acm.timus.ru/problem.aspx?space=1&num=1203
    MatrixDeity, 2016.
*/

#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int N = 10e5;
typedef pair<int, int> PR;

int n, ans(1);
PR tmp;
PR confs[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &confs[i].first, &confs[i].second);

    sort(confs, confs + n, [] (const PR& l, const PR& r) {
        if (l.second == r.second)
            return l.first < r.first;
        return l.second < r.second;
    });

    tmp = confs[0];
    for (int i = 1; i < n; ++i)
        if (tmp.second < confs[i].first)
        {
            tmp = confs[i];
            ++ans;
        }

    printf("%d", ans);
    return 0;
}
