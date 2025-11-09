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
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 +7 ; 
vector<vector<ll>> v(2) ; 
vector<ll> dp ; 
ll n ; 
ll dfs(ll i , ll state ){
    if( i >= v[0].size()) return 0 ; 
    if(dp[i][state] != -1 )return dp[i] ; 
    ll res = 0 ;
    ll a = (v[0][i] + v[0][i+1] + v[1][i] > 1) + (v[0][i+2] + v[1][i+1] + v[1][i+2] > 1) ;
    ll b =  (v[0][i] + v[1][i+1] + v[1][i] > 1) + (v[0][i+1] + v[0][i+2] + v[1][i+2] > 1) ;
    ll c =  (v[0][i] + v[0][i+1] + v[0][i+2] > 1) + (v[1][i] + v[1][i+1] + v[1][i+2] > 1) ;
    res = max({a , b , c }) ; 
    res = res + dfs(i + 3) ; 
    return dp[i] = res ; 
}
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        cin >> n ; 
        v.clear() ; 
        v.resize(2 , vector<ll>(n)) ; 
        for(ll i = 0 ; i < n ; i ++){
            char x ; cin >> x ; 
            if(x == 'A')v[0][i] = 1 ; 
            else v[0][i] = 0 ; 
        }
          for(ll i = 0 ; i < n ; i ++){
            char x ; cin >> x ; 
            if(x == 'A')v[1][i] = 1 ; 
            else v[1][i] = 0 ; 
        }
 
        dp.assign(n , -1 ) ; 
        cout << dfs(0) << endl ;
    } 
    return 0;
}