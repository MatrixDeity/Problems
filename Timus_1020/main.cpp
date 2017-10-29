/**
    Timus_1020
    http://acm.timus.ru/problem.aspx?space=1&num=1020
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

using Point = pair<double, double>;

const double PI = 3.14159;

double getDistance(Point& p1, Point& p2) {
    double dx = p2.first - p1.first;
    double dy = p2.second - p1.second;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    cout.setf(cout.fixed);
    cout.precision(2);
    int n;
    double r, ans(0.0);
    cin >> n >> r;
    vector<Point> vec(n);
    for (auto& item : vec) {
        cin >> item.first >> item.second;
    }
    ans += 2.0 * PI * r;
    if (n == 1) {
        cout << ans;
        return 0;
    }
    ans += getDistance(vec.front(), vec.back());
    for (int i = 1; i < n; ++i) {
        ans += getDistance(vec[i], vec[i - 1]);
    }
    cout << ans;
    return 0;
}
