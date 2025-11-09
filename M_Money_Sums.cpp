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
vector<vector<bool>> dp; 
vector<bool> us(1e5 +2 , 0 ) ; 
vector<ll> a ;
vector<ll> ans ;   

void pp(ll x , ll j){
     if(us[x + a[j]] == 0){
        ans.push_back(x+a[j]);
        us[x+a[j]] = 1 ; 
        }
}
void dfs(ll x , ll i){
    if(dp[x][i])return ;
    if(i >= a.size())return ; 
    pp(x , i) ; 
        dfs(x + a[i] , i+1 ); 
        dfs(x , i +1) ; 
    dp[x][i] = 1 ;
     
    return ; 
}
int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        a.resize(n) ; 
        for(ll & y : a)cin >> y ; 
        dp.assign(1e5 +2 , vector<bool>(n +1 , 0 )) ; 
        dfs(0 , 0) ; 
        sort(all(ans));
        cout << ans.size() << endl; 
        for(ll x : ans)cout << x << ' '; 

    }
    return 0;
}
