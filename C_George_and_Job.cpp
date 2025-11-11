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
ll n, m, k;
ll a[5002], pf[5002], sg[5002];
ll dp[5002][5002];

ll dfs(ll i, ll take)
{
    if (take == k)
        return 0;
    if (i > n)
        return -1e18 ;
    if (dp[i][take] != -1)
        return dp[i][take];

    ll res = dfs(i + 1, take); // skip
    if (i + m - 1 <= n)
    {
        res = max(res , dfs(i + m, take + 1) + sg[i] ) ;
    }
    return dp[i][take] = res;
}

int main()
{
    // بسم الله
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            pf[i] = pf[i - 1] + a[i];
        }
        for (ll i = 1; i + m - 1 <= n; i++)
        {
            sg[i] = pf[i + m - 1] - pf[i - 1] ;
        }
        memset(dp, -1, sizeof(dp));
        cout << dfs(1, 0);
    }
    return 0;
}
