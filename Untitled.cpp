#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 10; // adjust as needed

long long fact[N], invFact[N];

// Fast exponentiation: (a^b) % mod
long long modPow(long long a, long long b, int mod) {
    long long res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Precomputes factorials and inverse factorials
void precomputeFactorials() {
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    invFact[N - 1] = modPow(fact[N - 1], MOD - 2, MOD);
    for(int i = N - 2; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

// nCr % MOD
long long nCr(int n, int r) {
    if(r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precomputeFactorials();

    int t;
    cin >> t;
    while(t--) {
        cout << fact[5] << "\n";
    }

    return 0;
}
