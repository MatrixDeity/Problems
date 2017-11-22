/**
    YandexInternship2017_B
    https://contest.yandex.ru/contest/4085/problems/B/
    MatrixDeity, 2017.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, ans;
    bool isFirst(true), isBeg(true);
    getline(cin, str);

    int pos = 0;
    for (char c : str) {
        if (isspace(c))
            ++pos;
        else if (ispunct(c)) {
            cout << -1;
            return 0;
        } else
            break;
    }
    if (pos == (int) str.size()) {
        cout << -1;
        return 0;
    }
    while (pos < (int) str.size()) {
        if (isFirst) {
            if (!isBeg)
                ans.push_back(' ');
            ans.push_back(toupper(str[pos]));
            isFirst = false;
        } else if (isalpha(str[pos])) {
            ans.push_back(tolower(str[pos]));
        } else if (isspace(str[pos])) {
            ans.push_back(' ');
            while (isspace(str[pos + 1]) && pos + 1 < (int) str.size())
                ++pos;
        } else {
            if (isspace(ans.back()))
                ans.pop_back();
            ans.push_back('.');
            while (ispunct(str[pos + 1]) || isspace(str[pos + 1])) {
                if (ispunct(str[pos + 1]))
                    ans.push_back('.');
                ++pos;
            }
            isFirst = true;
            isBeg = false;
        }
        ++pos;
    }
    if (!ispunct(ans.back())) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i < (int) ans.size(); ++i) {
        if (ispunct(ans[i]) && ispunct(ans[i - 1])) {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
