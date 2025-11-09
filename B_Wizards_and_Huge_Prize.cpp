#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll int
#define ld double
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
ll n, l, k;
ll p[201];
ll a[201];
ld dp[206][206][402];
ld dfs(ll i, ll w, ll cap)
{
    if (cap < 0 || cap > 401)
        return 0;
    if (i == n)
    {
        return (w >= l && cap >= 200) ? 1.0 : 0;
    }
    if (dp[i][w][cap] != -1)
        return dp[i][w][cap];

    ld x = p[i] / 100.0;
    ld res = 0.0;

    res += (1.0 - x) * dfs(i + 1, w, cap);

    if (a[i] == -1)
    {
        res += x * dfs(i + 1, w + 1, cap - 1);
    }
    else
    {
        res += x * dfs(i + 1, w + 1, min((ll)(401), cap + a[i]));
    }

    return dp[i][w][cap] = res;
}
int main()
{
    // بسم الله
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> l >> k;
        for (ll i = 0; i < n; i++)
            cin >> p[i];
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        for (ll i = 0; i < 206; i++)
        {
            for (ll j = 0; j < 206; j++)
            {
                for (ll k = 0; k < 402; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        cout << fixed << setprecision(12) << dfs(0, 0, min((ll)(401), k + 200)) << endl;
    }
    return 0;
}
