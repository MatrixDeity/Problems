/**
    Timus_1084
    http://acm.timus.ru/problem.aspx?space=1&num=1084
    MatrixDeity, 2017.
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
    For third case:
        Suppose, ang(r, r):
            cos(ang / 2) = a / (2 * r)
            ang / 2 = arccos(a / (2 * r))
            ang = 2 * arccos(a / (2 * r))

        S_sec = r^2 * ang / 2
        S_tr = r^2 * sin(ang) / 2
        S_seg = S_sec - S_tr = r^2 * ang / 2 - r^2 * sin(ang) / 2
        4 * S_seg = 2 * r^2 * (ang - sin(ang))
        ANS = S_cir - 4 * S_seg = PI * r^2 - 2 * r^2 * (ang - sin(ang))
*/

const double PI = acos(-1.0);

int main() {
    double a, r, ans(0.0);
    cin >> a >> r;
    if (a / 2.0 >= r)
        ans = PI * r * r;
    else if ((sqrt(2.0) * a / 2.0) <= r)
        ans = a * a;
    else {
        double ang = 2.0 * acos(a / (2.0 * r));
        ans = PI * r * r - 2.0 * r * r * (ang - sin(ang));
    }
    cout.setf(cout.fixed);
    cout.precision(3);
    cout << ans;
    return 0;
}
