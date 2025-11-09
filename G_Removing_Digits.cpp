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
vector<ll> dp;
ll dfs(ll n)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    string s = to_string(n);
    ll res = 2e16;
    for (char& x : s)
    {
        ll y = x - '0';
        if(y && n >= y)
        res = min(res, dfs(n - y) + 1);
    }
    return dp[n] = res;
}
int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        dp.assign(n + 2 , -1);
        ll ans = dfs(n);
        cout << ans;
    }
    return 0;
}
