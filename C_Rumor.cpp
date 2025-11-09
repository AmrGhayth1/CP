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

void dfs(ll v , vector<ll> adj[] , vector<ll>& c , vector<bool>& vs  ){
    if(vs[v] )return ; 
    vs[v] = 1 ; 
    for(auto ch : adj[v] ){
        if(vs[ch] == 0){
            c[ch] = 0 ; 
        dfs(ch , adj , c , vs ) ; 
    }
}
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
         vector<ll>c(n+1 , 0 ) ;
         pair<ll,ll> p[n] ;  
         for(ll i = 1 ; i <= n ; i++ ){
            ll coins ; cin >> coins ; 
            c[i] = coins ; 
            p[i-1].first = coins ; 
            p[i-1].second = i ;
         }
         sort(p , p+n) ;
         vector<ll>adj[n+1] ; 
         for(ll i = 0 ; i < m ; i ++){
            ll x , y ; cin >> x >> y ; 
            adj[x].push_back(y) ;
            adj[y].push_back(x) ;
         }
         vector<bool> vs(n+1 ,0 ) ;
         for(ll i = 0 ; i < n ; i ++){
            dfs(p[i].second , adj , c , vs  ) ; 
         }

         ll ans = 0 ; 
         for(ll i = 1 ; i <= n ; i ++ ){
            ans += c[i] ; 
         } 
         cout << ans ; 
    }
    return 0;
}
