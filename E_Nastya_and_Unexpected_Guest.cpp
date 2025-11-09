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

int main()
{
    // بسم الله
    AMR

        ll n,
        m;
    cin >> n >> m;
    deque<ll> d(m);
    for (ll &y : d)
        cin >> y;
    ll g, r;
    cin >> g >> r ;
    sort(all(d));
    vector<vector<ll>> dp(m + 1, vector<ll>(g + 1, -1));
    auto dfs = [&](auto &&self, ll i, ll t) -> ll
    {
        if (n - d[i] > 
        if (dp[i][t] == -2)
            return 1e18;
        if (dp[i][t] != -1)
            return dp[i][t];

        dp[i][t] = -2; // visiting 

        ll res = 1e18;
        ll dff = abs(d[i + 1] - d[i]);
        if (dff <= t)
        {
            ll nx = t - dff ; 
            ll cost = dff ; 
            if(nx == 0 ){
                cost += r ; 
                nx = g ; 
            } 
            res = min(res, self(self, i + 1, nx ) + cost);
        }
        if (i != 0)
        {
            dff = abs(d[i] - d[i - 1]);
            
            if (dff <= t)
            {
            ll nx = t - dff ; 
            ll cost = dff ; 
            if(nx == 0 ){
                cost += r ; 
                nx = g ; 
            } 
                res = min(res, self(self, i - 1, nx ) + cost);
            }
        }

        return dp[i][t] = res;
    };
    ll ans = dfs(dfs, 0, g);
    if (ans >= 1e18){
        ans = -1;
    }
    cout << ans;
    return 0;
}