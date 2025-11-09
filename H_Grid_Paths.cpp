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
const ll MOD = 1e9 +7 ;  
typedef unsigned __int128 bll;
vector<string> g;
vector<vector<ll>> dp;
ll n;
ll dfs(ll i, ll j)
{
    if(i >= n || j >= n)return 0 ; 
    if (g[i][j] == '*')
        return 0;
    if (i == n - 1 && j == n - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll res = 0;
    if (i + 1 < n)
    {
        res =  (res%MOD + dfs(i + 1, j)%MOD)%MOD ;
    }
    if (j + 1 < n)
    {
        res = (res%MOD +  dfs(i, j + 1)%MOD )%MOD;
    }
    return dp[i][j] = res;
}
int main()
{
    AMR
    
        cin >> n;
        g.resize(n);
        dp.assign(n, vector<ll>(n, -1));
        for (string &x : g)
            cin >> x;
        cout << dfs(0, 0);

    return 0;
}