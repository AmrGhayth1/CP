#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

void dfs(ll u , ll p , ll sub[] , vector<ll> adj[] , vector<bool>& vs ){
    vs[u] = 1 ; 
    for(ll v : adj[u] ){
        if(v != p){
        if(!vs[v]){
            dfs(v , u , sub , adj , vs ) ; 
            sub[u] += sub[v] ;
        }
    }
 }
}
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
          ll sub[4005] ;  
         vector<ll> adj[4005] ; 
         vector<bool> vs(4005,0) ; 
 
        for(ll i = 0 ; i < n-1 ;  i ++){
            ll x ; cin >> x; 
            adj[i+2].push_back(x) ; 
            adj[x].push_back(i+2) ; 
        }
        string s ; 
        cin >> s ; 
        for(ll i = 0 ; i < s.size() ; i ++){
            if(s[i] == 'B'){
                sub[i+1] = 1 ;
            }else{
                sub[i+1] = -1 ;  
            }
        }
        ll ans = 0 ; 
        dfs( 1 , 0  , sub , adj , vs ) ; 
        for(ll i = 1 ; i <= n ; i ++){
            if(sub[i] == 0)ans ++ ; 
        }
        cout << ans << endl ;
    }
    return 0;
}
