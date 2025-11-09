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
const ll MOD = 1e9 + 7 ; 
vector<ll> dp(2e6 , -1 ) ; 
ll fn(ll n , vector<ll>& a ){
    if(n == 0 )return 1 ; 
    if(dp[n] != -1 )return dp[n] ;
    dp[n] = 0 ;
    for(ll y : a){
        if(y <= n)
        dp[n] = (dp[n] %MOD + fn( n-y , a) % MOD)%MOD  ; 
    }
    return dp[n] ; 
}
int main()
{
    AMR
    ll t = 1 ;
    // cin >> t;
    while (t--)
    {
        ll n , m ; 
        cin >> n >>m ; 
        vector<ll> a(n) ; 
       
        for(ll & y : a)cin >> y ; 
        ll ans = fn(m , a) ; 
        cout << ans ;  

    }
    return 0;
}
