/**
    Timus_1290
    http://acm.timus.ru/problem.aspx?space=1&num=1290
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& item : vec)
        cin >> item;
    sort(vec.begin(), vec.end(), greater<int>());
    for (int item : vec)
        cout << item << '\n';
    return 0;
}
