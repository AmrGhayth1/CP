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
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;
const ll N = 2e5 + 5;
vector<ll> spf(N);
 
void sieve()
{
    for (ll i = 0; i < N; i++)
        spf[i] = i;
    for (ll i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
vector<vector<ll>> factors(N);

void precompute_factors() {
    for (ll i = 2; i < N; i++) {
        ll x = i;
        while (x != 1) {
            ll p = spf[x];
            factors[i].push_back(p);
            while (x % p == 0) x /= p;
        }
    }
}

int main()
{
    // بسم الله
    AMR
    sieve() ; 
    precompute_factors() ; 
    ll t = 1;
    cin >> t;
next:
    while (t--)
    {
        ll n;
        
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll &y : b)
            cin >> y;
        
        ll ans = 2 ;
        vector<ll> m(N , 0 ) ;
        for (ll i = 0; i < n; i++)
        {
            for (ll &e : factors[a[i]])
                m[e]++;
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll &e : factors[a[i]])
                m[e]--;
            for (ll j = 0; j < 2 ; j += b[i]){
                for (ll &e : factors[a[i] + j ])
                if (m[e])
                    ans = min(ans, j);
            }
            for (ll &e : factors[a[i]])
                m[e]++;
        }
        cout << ans << endl;
    }
    return 0;
}
