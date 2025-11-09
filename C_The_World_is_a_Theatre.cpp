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
 
ll C(ll n, ll k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    ll res = 1;
    for (ll i = 1; i <= k; ++i) {
        res *= n--;
        res /= i;
    }
    return res;
}
 
int main()
{
    AMR
    ll tt = 1 ;
   //cin >> t;
    while (tt--)
    {
        ll n , m , t ; 
        cin >> n >> m >> t ; 
 
        ll ans  = 0 ; 
        for(ll i = 4 ; i <= min(n, t-1 ) ; i ++){
            ll x = C(n , i) ; 
            ll y = C(m , t -i) ; 
            ans += y * x ;
    }
        cout << ans ;
    }
    return 0;
}