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
string s, tg;
vector<vector<ll>> dp(5002, vector<ll>(5002, -1));

ll dfs(ll i, ll j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (j >= s.size())
        return tg.size() - i;
    if (i >= tg.size())
        return s.size() - j;
    ll res = 1e17;
    if (s[j] == tg[i])
    {
        res = dfs(i + 1, j + 1);
    }
    else
    {
        res = min(res, dfs(i, j + 1) + 1);     // remove
        res = min(res, dfs(i + 1, j + 1) + 1); // swap
        res = min(res, dfs(i + 1, j) + 1);     // insert
    }
    return dp[i][j] = res;
}
int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> s >> tg;
        if (s == tg)
        {
            cout << 0;
            continue;
        }
        cout << dfs(0, 0);
    }
    return 0;
}
