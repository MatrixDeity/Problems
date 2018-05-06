#include <iostream>
#include <vector>

using namespace std;

using ld = long double;

int main() {
    cout.setf(ios_base::fixed);
    cout.precision(12);
    int n;
    cin >> n;
    vector<ld> PH(n), PAH(n);
    ld PA = 0.0L;
    for (int i = 0; i < n; ++i) {
        cin >> PH[i] >> PAH[i];
        PH[i] /= 100.0L;
        PAH[i] /= 100.0L;
        PA += PH[i] * PAH[i];
    }
    for (int i = 0; i < n; ++i) {
        ld ans = (PH[i] * PAH[i]) / PA;
        cout << ans << endl;
    }
    return 0;
}
