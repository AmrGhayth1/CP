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
ll a[105][105];
ll ans[105];
ll lz[105];
ll w[105][105];
ll sz[105];
int main()
{
    // بسم الله
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= m; j++)
                cin >> a[i][j];

        for (ll k = 1; k <= m; k++)
        {
            for (ll i = 1; i <= k; i++)
                sz[i] = 0;
            for (ll i = 1; i <= n; i++)
            {
                if (ans[i])
                    continue;
                ll c = a[i][k];
                if (c == 0)
                    continue;
                if (lz[c])
                    ans[i] = k;
                else
                    w[c][sz[c]++] = i;
            }
            for (ll c = 1; c <= k; c++)
                if (sz[c] > 1)
                {
                    lz[c] = 1;
                    for (ll j = 0; j < sz[c]; j++)
                    {
                        ll x = w[c][j];
                        if (!ans[x])
                            ans[x] = k;
                    }
                }
        }
        for (ll i = 1; i <= n; i++)
            cout << ans[i] << endl;
    }
    return 0;
}
