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
ll mx = 0 ; 
ll cnt = 0 ; 
void dfs(ll v , vector<ll>adj[] ,vector<ll>& vis , vector<ll> dep){
    vis[v] = 1 ;
    for(ll ch : adj[v]){
        if(vis[ch] == 0){
            dep[ch] = dep[v]+1 ; 
        dfs(ch , adj , vis , dep ) ; 
    }else if(vis[ch] == 1){
        mx =max(mx , dep[v] - dep[ch]+ 1 ) ;
    }
}
vis[v] = 2 ; 
}
int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n , m ; 
        cin >> n >> m ; 
        vector<ll> adj[n+1] ; 
        vector<ll> vis(n+1 , 0) ;
        vector<ll> dep(n+1 , 1 ) ;  
        for(ll i = 0 ; i < m ; i ++){
            ll x , y ; 
            cin >> x >> y ; 
            adj[x].push_back(y) ;
            adj[y].push_back(x) ;
        } 
         mx= 0 ; 
         dfs( 1, adj , vis , dep ) ; 
        for(ll i = 1 ; i <= n ; i++){ 
            if(vis[i] == 0 ){
                cout << "NO" ; 
                return 0 ; 
            }
        }
        if(mx >= 3 && n == m ){
            cout << "FHTAGN!" ; 
        }else{
            cout << "NO" ;
        }
    }
    return 0;
}