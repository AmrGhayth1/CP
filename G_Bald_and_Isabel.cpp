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
        ll t = 1;
    cin >> t;
    next :
    while (t--)
    {
        ll n , k , q ;
        cin >> n >> k >> q ; 
        vector<bool> s(n+1 , 0 ) ; 
        for(ll i = 0 ; i < k ; i ++){
            ll x; 
            cin >> x ; 
            s[x] = true ; 
        }
        vector<ll> adj[n+1] ; 
        for(ll i = 0 ; i < n-1 ; i ++){
            ll x , y ; 
            cin >> x >> y ; 
            adj[x].push_back(y) ; 
            adj[y].push_back(x) ; 
        }
        vector<ll> ans(n+1 , 0 ) ;  
        vector<ll> dp(n+1 , -1 ) ;  
        ll node = -1  ; 
        auto dfs(auto &&self , ll v)->ll{
            if(dp[v] != -1)return dp[v] ; 
            ll mx1 = 0 ; 
            for(ll ch : adj[v]){
                    ll x = self(self , ch ) ; 
                    mx1 = max(mx1 , x ) ; 
            }
            return dp[v] = (mx1 + s[v] )  ;   
        };
        ll X = *max_element(all(dp)) ; 
        while(q --){
            ll x ; 
            cin >> x;  
            if(dp[x] == X){
                cout << "JA" << endl;
            }else{
            cout << "NEIN" << endl ;
        }
    }
    return 0;
}
