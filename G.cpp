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
ll a[200002];
int dp[200002][3][2][2][2];
bool dfs(ll i, int tg, bool P0, bool P1, bool P2)
{
    if (i != n)
    {
        if (a[i] == 0)
            P0 = true;
        if (a[i] == 1)
            P1 = true;
        if (a[i] == 2)
            P2 = true;
    }
    int mex = 0 ; 
    if (P0)
    {
        mex = 1;
        if (P1)
        {
            mex = 2;
            if (P2)
            {
                mex = 3;
            }
        }
    }
      // cout << i << ' '<< tg << ' '<< mex << endl ; 
    if (i == n)
    {
        return (tg == 2 && mex == 2);
    }
    if (a[i] == tg)
        return 0;
    if (dp[i][tg][P0][P1][P2] != -1)
        return dp[i][tg][P0][P1][P2];
    bool res = 0;
    if (mex == tg)
    {
        if (tg != 2)
        {
            res = (res || dfs(i + 1, tg + 1, 0, 0, 0));
        }
    }
    if (mex <= tg )
    {
        res = (res || dfs(i + 1, tg, P0, P1, P2));
    }
  
    return dp[i][tg][P0][P1][P2] = res;
}
int main()
{
    // بسم الله
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for(ll i = 0 ; i <= n ; i ++){
            for(int tg = 0 ; tg <= 3 ; tg ++ ){
                dp[i][tg][0][0][0] = -1 ; 
                dp[i][tg][1][0][0] = -1 ; 
                dp[i][tg][0][1][0] = -1 ; 
                dp[i][tg][1][1][0] = -1 ; 
                dp[i][tg][0][0][1] = -1 ; 
                dp[i][tg][1][0][1] = -1 ; 
                dp[i][tg][0][1][1] = -1 ; 
                dp[i][tg][1][1][1] = -1 ; 
            }
        }
        if (dfs(0, 0, 0, 0, 0))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
