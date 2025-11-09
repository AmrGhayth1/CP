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
vector<ll> a;
vector<ll> dp(1e6 + 10, -1);
ll dfs(ll i, ll n) {
    if (i == n - 1) return 0;
    if (dp[i] == -2) return 1e8;
    if (dp[i] != -1) return dp[i];

    dp[i] = -2;
    ll res = 1e8;

    if (a[i] == -2) {
        // '#' cell → move back 2 steps, if allowed
        if (i - 2 >= 0) {
            res = min(res, dfs(i - 2, n) + 1);
        }
    }
    else if (a[i] == 0) {
        // '.' cell → only move forward 1
        if (i + 1 < n) {
            res = min(res, dfs(i + 1, n) + 1);
        }
    }
    else {
        // digit → two options:
        if (i + 1 < n) {
            res = min(res, dfs(i + 1, n) + 1);
        }
        if (i + a[i] < n) {
            res = min(res, dfs(i + a[i], n) + 1);
        }
    }

    return dp[i] = res;
}

int main()
{
    shay_blbn
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        for (ll i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (ll j = 0; j < m; j++)
            {
                if (s[j] == '#')
                    a.push_back(-2);
                else if (s[j] == '.')
                    a.push_back(0); 
                else
                    a.push_back(s[j] - '0');
            }
        }
        ll ans = dfs(0, n* m );
    if (ans >= 1e8) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
    }
    return 0;
}