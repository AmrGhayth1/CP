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


  vector<ll> adj[200005] ;
  vector <ll> p ;  
  vector<bool> vs(200005 , 0) ; 
   ll sub[200005] ; 
  
  void dfs2( ll pr , ll u  ){
    sub[u] = 1 ; 
    for(ll v : adj[u] ){
        if(v != pr){
            dfs2( u , v ) ; 
            sub[u] += sub[v] ;
        }
    }
  }

  void dfs(ll x , ll cnt ){
    vs[x] = 1 ;  
    p.push_back(cnt - sub[x] +1 ) ;
    for(ll child : adj[x]){
        if(!vs[child]){
            dfs(child , cnt + 1 ) ;   
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
        ll n , k ; 
        cin >> n >> k ;
       
        for(ll i = 0 ; i < n-1 ; i ++){
            ll x , y ; 
            cin >> x >> y ; 
            adj[x].push_back(y) ; 
            adj[y].push_back(x) ; 
        }
        dfs2( 0 , 1 ) ; 
        dfs(1  , 0 ) ;

        sort(all(p)) ;
        ll cnt = 0 ; 
        ll ans =0 ; 
        for( ll i = p.size() -1 ; i >= 0 ; i --){
            cnt ++ ; 
            ans += p[i] ;
            if(cnt == k )break ;  
        }
        cout << ans ;
 
    }
    return 0;
}