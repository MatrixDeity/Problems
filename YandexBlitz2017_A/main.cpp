/**
    YandexBlitz2017_A
    MatrixDeity, 2017.
*/

#include <iostream>

using namespace std;

int main() {
    int n, pScore(0), vScore(0);

    cin >> n;
    int pCard(0), vCard(0);
    for (int i = 0; i < n; ++i) {
        int card;
        cin >> card;
        switch (i % 3) {
            case 0:
                pScore += card;
                pCard = card;
                break;
            case 1:
                vScore += card;
                vCard = card;
                break;
            case 2:
                if (pCard > vCard)
                    vScore += card;
                else
                    pScore += card;
                break;
        }
    }

    cout << (pScore > vScore ? "Petya" : "Vasya");
    return 0;
}
