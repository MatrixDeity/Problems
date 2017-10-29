/**
    Timus_1021
    http://acm.timus.ru/problem.aspx?space=1&num=1021
    MatrixDeity, 2017.
*/

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    const int NUM = 1e4;
    unordered_set<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        st.insert(NUM - a);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (st.find(a) != st.end()) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
