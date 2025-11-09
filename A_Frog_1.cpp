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
vector<ll> dp(1e6, -1);
ll fn(vector<ll>& a, ll n, ll v )
{
    if (v == n - 1) return 0;
    if(dp[v] != -1 )return dp[v] ; 
    dp[v] = abs(a[v] - a[v + 1]) + fn(a , n , v + 1) ; 
    if(v != n-2){
        dp[v] = min(dp[v] , abs(a[v] - a[v + 2]) + fn(a , n , v + 2) ) ; 
    }
    return dp[v];
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
        vector<ll> a(n);
        for (ll &y : a)
            cin >> y;

            cout << fn(a , n , 0 ) ; 
    }
    return 0;
}
