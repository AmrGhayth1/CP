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
int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, m, e;
        cin >> n >> m >> e;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll ans = 0;
        for (ll i = 0; i < 24; i++)
        {
            ll x = n;
            for (ll j = 0; j < n; j++)
            {
                ll start = a[j];
                ll end = (a[j] + e -1) % 24;
                if(e == 0){
                    continue;
                }
                for (ll k = i; k < (i + m) ; k++)
                {
                    ll ind = k % 24;
                    if (start <= end)
                    {
                        if (ind >= start && ind <= end)
                        {
                            x--;
                            break;
                        }
                    }
                    else
                    {
                        if (ind >= start || ind <= end)
                        {
                            x--;
                            break;
                        }
                    }
                }
            }
            ans = max(ans, x);
        }
        cout << ans << endl;
    }
    return 0;
}
