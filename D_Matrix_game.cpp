#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

const ll MOD = 1e9 + 7;
const ll N = 1e5 + 10;

ll fct[N], invfct[N];

ll modPow(ll a, ll b, ll mod) {
    ll res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

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
    factorials(); 

    ll t;
    cin >> t;
    while(t--){
        ll a , b , k  ;
        cin >> a >> b >> k  ;   
        ll n = ((a - 1) % MOD) * (k % MOD) % MOD;
        n = (n + 1) % MOD;

        ll top = 1;
        for (ll i = 0; i < a; i++) {
            top = top * ((n - i + MOD) % MOD) % MOD;
        }

        ll c = top * invfct[a] % MOD;

        ll m = (((b - 1) % MOD) * (k % MOD)) % MOD;
        m = m * c % MOD;
        m = (m + 1) % MOD;

        cout << n << ' ' << m << endl;
    }

    return 0;
}
