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

void dfs(ll u , ll v , vector<ll> adj[] ,  vector<ll>& s){
    s.push_back(v ) ; 
    for(ll ch : adj[v]){
        if(ch != u){
            dfs(v , ch , adj , s ) ;
        }
    } 
}
ll dfs2(ll u , ll v , vector<ll> adj[] ,  vector<ll>& sz ){ 
    for(ll ch : adj[v]){
        if(ch != u){
           sz[v] += dfs2(v , ch , adj , sz ) +1 ;         
        }
    }
    return sz[v] ; 
}

int main()
{
    AMR
    ll t = 1 ;
  // cin >> t;
    while (t--)
    {
        ll n , m ; 
        cin >> n >> m ;
        vector<ll> adj[n+1] ;  
        for(ll i = 2 ; i<= n ; i ++ ){
            ll x ; cin >> x ; 
            adj[x].push_back(i) ;
        }
        map<ll,ll> ind ; 
        vector<ll> s ; 
        dfs(-1 , 1 , adj , s) ; 
        for(ll i = 0 ; i  < s.size() ; i ++){
           ind[s[i]] = i ; 
        }
        vector<ll> sz(n+1 , 0 ) ;
        dfs2(-1 , 1 , adj , sz ); 
        for(ll i = 0 ; i < m ; i++){
            ll x , y ; 
            cin >> x >> y ; 
            if(y-1 > sz[x]){
                cout << -1 << endl ;
            }else{ 
            cout << s[ind[x]+y-1] << endl ;
        }
    }
    }
    return 0;
}
