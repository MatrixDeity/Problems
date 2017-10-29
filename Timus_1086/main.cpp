/**
    Timus_1086
    http://acm.timus.ru/problem.aspx?space=1&num=1086
    MatrixDeity, 2017.
*/

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

void getPrimes(vector<ll>& primes) {
    const ll sz = 2e5;
    vector<bool> sieve(sz, true);
    for (ll i = 2; i < sz; ++i) {
        if (sieve[i]) {
            for (ll j = i * i; j < sz; j += i) {
                sieve[j] = false;
            }
        }
    }
    primes.reserve(1.8e4);
    for (ll i = 2; i < sz; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    ll n;
    cin >> n;
    vector<ll> primes;
    getPrimes(primes);
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        cout << primes[a - 1] << endl;
    }
    return 0;
}
