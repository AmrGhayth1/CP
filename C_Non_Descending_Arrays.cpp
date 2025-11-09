#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
const ll MOD = 998244353;
 
int main()
{
    // بسم الله
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
     ll a[n ] ; 
     ll b[n ] ; 
     for(ll & y : a)cin >> y ; 
     for(ll & y : b)cin >> y ; 
     ll dp[n+1][2] ; 
     dp[n][0] = 1 ; 
     dp[n][1] = 1 ;
     for(ll i = n-1 ; i >= 0 ; i --){
        dp[i][0] = 0 ; 
        dp[i][1] = 0 ; 
        ll x = i == n-1 ? 1e18 : a[i+1] ; 
        ll y = i == n-1 ? 1e18 : b[i+1] ; 
        if(a[i] <= x && b[i] <= y){
            dp[i][0] = ( dp[i][0]%MOD + dp[i+1][0]%MOD )%MOD ;
            dp[i][1] = (dp[i][1] %MOD + dp[i+1][0]%MOD )%MOD ;
        }
        if(a[i] <= y && b[i] <= x){
            dp[i][0] = ( dp[i][0]%MOD + dp[i+1][1]%MOD )%MOD ;
            dp[i][1] = (dp[i][1] %MOD + dp[i+1][1]%MOD )%MOD ;
        }
     }
 
        cout << dp[0][0] << endl; 
    }
    return 0;
}