#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long long int lli;
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
#define MOD 1000000007

const int N = 1000001;

ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];
 
void InverseofNumber() {
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++) {
        naturalNumInverse[i] = naturalNumInverse[MOD % i] * (MOD - MOD / i) % MOD;
    }
}

void InverseofFactorial() {
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++) {
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % MOD;
    }
}
 
void factorial() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
 
ll nCr(ll R, ll N) {
    ll ans = ((fact[N] * factorialNumInverse[R]) % MOD * 
                factorialNumInverse[N - R]) % MOD;
    return ans;
}

long long moduloMultiplication(long long a, long long b) {
    long long res = 0;
    a %= MOD;
 
    while (b) {
        if (b & 1) res = (res + a) % MOD;
        a = (2 * a) % MOD; b >>= 1;
    }
    return res;
}

void init() {
    InverseofNumber();
    InverseofFactorial();
    factorial();
}

void solve() {
    int m, n; cin >> n >> m;
    int ans = 0, end = min((2 * n - 1), (m - 1));

    FLT (i, n, end) {
        ans =  (moduloMultiplication(nCr((m - 2 * n + 1 + i), 
                (2 * (m - n))), nCr(i, (2 * n - 1))) + ans) % MOD;
    }

    cout << ans << endl;
}
 
int main() {
    int TC = 0; cin >> TC;
    init();
    while (TC--)
        solve();
 
    return 0;
}