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
ll n, h, l, r;
vector<ll> a;
ll dp[2001][4001];
ll dfs(ll i, ll time)
{
    if (dp[i][time] != -1)
        return dp[i][time];
    if (i == n)
        return 0;
    ll res = 0;
    ll x = 0, y = 0;
    ll time1 = (time % h + a[i] % h) % h;
    ll time2 = (time % h + a[i] % h - 1) % h;
    if (time1 >= l && time1 <= r)
        x = 1;
    if (time2 >= l && time2 <= r)
        y = 1;
    res = max(res, dfs(i + 1, time1) + x);
    res = max(res, dfs(i + 1, time2) + y);
    return dp[i][time] = res;
}
int main()
{
    // بسم الله
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> h >> l >> r;
        a.resize(n);
        memset(dp, -1, sizeof(dp));
        for (ll &y : a)
            cin >> y;
        cout << dfs(0, 0);
    }
    return 0;
}
