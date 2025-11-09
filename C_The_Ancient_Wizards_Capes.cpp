#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    // بسم الله
    AMR
    ll t = 1;
    cin >> t;
next:
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n + 1), s(n);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];

        for (ll i = 1; i < n; i++)
        {
            ll d = a[i + 1] - a[i];
            if (d < -1 || d > 1)
            {
                cout << 0 << endl;
                goto next;
            }
            s[i] = d + 1;
        }

        auto val = [&](vector<ll> &l)
        {
            vector<ll> p(n + 1);
            for (ll i = 1; i <= n; i++)
                p[i] = p[i - 1] + l[i];
            ll L = p[n];
            for (ll i = 1; i <= n; i++)
            {
                ll sr = (n - i + 1) - (L - p[i - 1]);
                if (p[i] + sr != a[i])
                    return 0LL;
            }
            return 1LL;
        };

        ll ans = 0;
        for (ll j = 0; j <= 1; j++)
        {
            vector<ll> l(n + 1, -1);
            l[1] = j;
            vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));

            auto dfs = [&](auto &&self, ll i, ll c)
            {
                if (i == n)
                    return val(l);
                ll &res = dp[i][c];
                if (res != -1)
                    return res;
                res = 0;
                ll nx = s[i] - c;
                if (nx == 0 || nx == 1)
                {
                    l[i + 1] = nx;
                    res = (res + self(self, i + 1, nx)) % MOD;
                }
                return res;
            };

            ans = (ans + dfs(dfs, 1, j)) % MOD;
        }

        cout << ans % MOD << endl;
    }
    return 0;
}
