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
ll n = 2000005;
vector<vector<ll>> prime_factors(n + 1);
void sieve()
{

    vector<ll> spf(n + 1);
    iota(spf.begin(), spf.end(), 0);

    for (ll i = 2; i * i <= n; ++i)
        if (spf[i] == i)
            for (ll j = i * i; j <= n; j += i)
                if (spf[j] == j)
                    spf[j] = i;

    for (ll i = 2; i <= n; ++i)
    {
        ll x = i;
        while (x > 1)
        {
            prime_factors[i].push_back(spf[x]);
            x /= spf[x];
        }
    }
}
int main()
{
    // بسم الله
    AMR
    sieve();
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
        ll mn1 = 1e18, mn2 = 1e18;
        for (ll &y : b)
        {
            cin >> y;
            if (y < mn1)
            {
                mn2 = min(mn1, mn2);
                mn1 = y;
            }
            else
            {
                mn2 = min(mn2, y);
            }
        }
        ll ans = mn1 + mn2;
        vector<ll> m(2000005, 0);
        for (ll i = 0; i < n; i++)
        {
            for (ll &e : prime_factors[a[i]])
                m[e]++;
        }
        for (ll i = 0; i <= 2 ; i++)
        {
            for (ll &e : prime_factors[a[i]])
                m[e]--;
            for (ll j = 0; j < ans && j < 200005 ; j += b[i])
            {
                for (ll &e : prime_factors[a[i] + j])
                        if (m[e])
                            ans = min(ans, j);
            }

            for (ll &e : prime_factors[a[i]])
                m[e]++;
        }
        cout << ans << endl;
    }
    return 0;
}
