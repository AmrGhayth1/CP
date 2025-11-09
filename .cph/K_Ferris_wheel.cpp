#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

const ll MOD = 1e9 + 7;
const ll N = 1e7 + 10; // adjust as needed

long long fct[N], invfct[N];

// Fast exponentiation: (a^b) % mod
long long modPow(long long a, long long b, ll mod) {
    long long res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Precomputes factorials and inverse factorials
void factorials() {
    fct[0] = 1;
    for(ll i = 1; i < N; i++)
    fct[i] = (fct[i - 1] * i) % MOD;

        invfct[N - 1] = modPow(fct[N - 1], MOD - 2, MOD);
    for(ll i = N - 2; i >= 0; i--)
    invfct[i] = (invfct[i + 1] * (i + 1)) % MOD;
}

int main()
{
    AMR
    ll t = 1;
    factorials();
    while (t--)
    {
        string s; 
        map<char, ll> f; 
        cin >> s; 
        fi(1, s.size()) {
            f[s[i]]++; 
        }
        
        ll n = s.size();
        ll ans = fct[n-1];
        
        for(auto &p : f) {
            ans = (ans * invfct[p.second]) % MOD;
        }
        
        cout << ans<< endl;
    }
    return 0;
}