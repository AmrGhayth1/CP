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
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n + 1);
        for (ll &y : a)
            cin >> y;

        vector<ll> dp(n + 1, -1);

        auto dfs = [&](auto &&self, ll i) -> ll
        {
            if (i < 0)
                return 1e18;
            if (i == 0)
                return 0;
            if (dp[i] != -1)
                return dp[i];
            ll res = 1e18;
            for (ll d = 1; d * d <= a[i]; d++)
            {
                if (a[i] % d == 0)
                {
                    ll x = i - d;
                    ll y = i - (a[i] / d);

                    res = min(res, 1 + self(self, x));
                    res = min(res, 1 + self(self, y));
                }
            }
            return dp[i] = res;
        };

        ll ans = dfs(dfs, n);
        if (ans >= 1e18)
            ans = -1;

        cout << ans << endl;
    }
    return 0;
}
