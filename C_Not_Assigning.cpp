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
void dfs(ll u , ll v  , vector<ll> adj[] ,  map<pair<ll,ll>,ll>& m , ll dep ){
    if(dep %2 == 0 ){
        m[{min(u,v) , max(u,v ) } ] = 2 ; 
    }else{
        m[{min(u,v) , max(u,v ) } ] = 5 ; 
    }

    for(ll ch : adj[v] ){
        if(ch != u ){
        dfs(v , ch , adj , m , dep +1 ) ;
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
        ll n ; cin >> n ; 
        vector<ll> adj[n+1] ; 
        pair<ll,ll> p[n-1] ;
        for(ll i = 1 ; i < n ; i ++){
            ll x , y ; cin >> x >> y ; 
            adj[x].push_back(y) ;
            adj[y].push_back(x) ;
            p[i-1].first = x ; 
            p[i-1].second = y ; 
        }
        bool ans = 0 ;
        ll r = 1 ; 
        for(ll i = 1 ; i <= n ; i ++){
            if(adj[i].size() > 2 )ans = 1 ;

            if(adj[i].size() == 1 )r = i ;
        }
        if(ans){
            cout << -1 << endl ;
            continue; 
        }
        map<pair<ll,ll>,ll> m ;  
        dfs(-1 , r , adj , m , 0 ) ;
        
        for(ll i = 0 ; i < n-1 ; i ++){
            ll y = min(p[i].first , p[i].second );
            ll x = max(p[i].first , p[i].second );
            cout << m[{y,x}] << ' ';
        }
        cout << endl ;
    }
    return 0;
}
