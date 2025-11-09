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
#define shay_blbn            \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;
int main()
{
    shay_blbn
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> v(32, 0);
        ll xr = 0;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            xr ^= x;
            for (ll j = 0; j < 32; j++)
            {
                if (((1LL << j) & x) != 0)
                {
                    v[j]++;
                }
            }
        }
        bool T = 0;
        ll ans = 0;
        if (xr >= m)
        {
            cout << 0;
            return 0;
        }
        for (ll i = 31; i >= 0; i--)
        {
            if (((1LL << i) & xr) == 0)
            {
                if (v[i] != n)
                {
                    ans++;
                    xr |= (1LL << i);
                }
            }
            if (xr >= m)
                break;
        }
        if (xr >= m)
        {
            cout << ans;
        }
        else
        {
            cout << -1;
        }
    }
    return 0;
}
