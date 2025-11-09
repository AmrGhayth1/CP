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
ll n;
ll a[3001];
ll b[3001];
ll c[3001];
ll dp[3001][2] ; 
ll dfs(ll i, bool x) {
    if (i > n) return 0; 
    if (dp[i][x] != -1) return dp[i][x];

    if (i == n) {
        return dp[i][x] = (x ? b[i] : a[i]);
    }

    ll op1 = (x ? b[i] : a[i]) + dfs(i+1, 1); // feed now 

    ll op2 = (x ? c[i] : b[i]) + dfs(i+1, 0);// feed after

    return dp[i][x] = max(op1, op2) ;
}
int main()
{
    // بسم الله
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
         cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++) cin >> b[i];
    for (ll i = 1; i <= n; i++) cin >> c[i];
    memset(dp, -1, sizeof(dp));

    cout << dfs(1, 0) << endl ;
    }
    return 0;
}
