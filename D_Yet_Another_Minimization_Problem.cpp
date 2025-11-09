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
vector<ll> a ; 
vector<ll> b ; 
ll dp[100][10000] ;
ll n ; 
ll dfs(ll i , ll smB , ll smA  ){
    if(i == n){
        return 0 ; 
    }
    if(dp[i][smA] != -1)return dp[i][smA] ; 
    ll x = b[i] ; 
    ll y = a[i] ; 
    ll res = 1e17 ;  
    res = min( dfs( i +1 , smB +x , smA + y )  + x*2*smB  + y*2*smA  , res ) ;  
    res = min ( dfs( i +1 , smB +y , smA + x ) + y*2*smB + x*2*smA , res ) ; 
    return dp[i][smA] = res ; 
}
int main()
{
    //بسم الله
    AMR
    ll t = 1 ;
  cin >> t;
    while (t--)
    {
        ll sm = 0 ; 
        cin >> n ; 
        for(ll i = 0 ; i < n ; i ++){
            ll x ; 
            cin >> x ; 
            sm += pow(x , 2) * (n-1) ; 
            a.push_back(x) ; 
        }
          for(ll i = 0 ; i < n ; i ++){
            ll x ; 
            cin >> x ; 
            sm += pow(x , 2) * (n-1) ; 
            b.push_back(x) ; 
        }
        reverse(all(a)) ;
        reverse(all(b)) ; 
        memset(dp ,-1 ,  sizeof(dp) ) ; 
        cout << sm + dfs(0 , 0 , 0 ) << endl ; 
    }
    return 0;
}
