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
map<ll, ll> dp;
ll dfs(ll n)
{
    if (n <= 0)
        return 0;
    if (dp.count(n))
        return dp[n];
    ll a = n / 2;
    ll b = n / 3;
    ll c = n / 4;
    ll res = 0;
    res += max(a, dfs(a)) + max(c, dfs(c)) + max(b, dfs(b));
    return dp[n] = max(res , n) ;
}
int main()
{
    AMR
        ll n;
    while (cin >> n)
    {
        cout << dfs(n) << endl;
    }
    return 0;
}
