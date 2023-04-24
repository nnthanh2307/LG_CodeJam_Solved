#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FLT(i, a, b) for(int i = (a); i <= (b); i++)
#define FGT(i, a, b) for(int i = (a); i >= (b); i--)
#define FG(i, a, b) for(int i = (a); i > (b); i--)

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
 
void solve() {
    double p = 0.00, b;
    int _min = 10001, _max = -1;
    ll a, n, x;
    cin >> n >> x;

    FOR (i, 0, n) {
        double temp; cin >> temp; p += temp;
    }

    FLT (f, 0, 10000) {
        double t = (1.00 + f / 100.00) * p;
        a = 10000 * t; b = (0.00 + a) / 10000;
        if ((x > t && (x - b <= 0.01)) || x == t || (x < t && x == floor(b))) {
            _min = (_min > f) ? f : _min;
            _max = (_max < f) ? f : _max;
        }
        if (floor(b) > x) break;
   }

   cout << _min << " " << _max << "\n";
}
 
int main() {
    int TC = 0; cin >> TC;

    while (TC--)
        solve();
 
    return 0;
}