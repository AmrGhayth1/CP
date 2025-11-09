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
ll n, m;
vector<ll> a, b;
vector<vector<ll>> dp(201, vector<ll>(1e5, -1));
ll dfs(ll ans, ll i)
{
    if (i == n)
        return ans;
    if (dp[i][ans] != -1)
        return dp[i][ans];
    ll res = 1e17;
    for (ll j = 0; j < m; j++)
    {
        
            ll x = ans;
            x |= (a[i] & b[j]);
            res = min(res, dfs(x, i + 1));
    }
    return dp[i][ans] = res;
}

int main()
{
    shay_blbn
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        a.resize(n);
        b.resize(m);
        for (ll &y : a)
            cin >> y;
        for (ll &y : b)
            cin >> y;
        cout << dfs(0, 0);
    }
    return 0;
}
