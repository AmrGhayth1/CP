#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 +7 ; 
const ll N = 1e7 + 1 ; 
vector<bool> is_prime(N, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
       }
   }
}

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
    factorials() ; 
    sieve() ; 
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ;
        ll ans = 0 ;  
        for(ll i = 1 ; i <= n ; i ++){
            if(is_prime[i]){
                ll x = fct[n]%MOD ;
                x = (x * invfct[i]%MOD )%MOD ; 
                x = (x  * invfct[n-i]%MOD )%MOD ;
                ans = (ans%MOD + x%MOD)%MOD ; 
            }
        }
        cout << ans << endl; 
    }
    return 0;
}
