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

bool dfs( vector<ll>adj[] , ll x , ll y , vector<bool>& v ){
    v[x] = 1 ; 
    for(ll child : adj[x] ){
        if(!v[child]){
            if(child == y)return 1 ; 
           if( dfs(adj , child , y , v ) )return 1 ; 
        }
    }
    return 0 ; 
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
        vector<ll> adj[101][101] ;
        for(ll i = 0 ; i < m ; i ++){
            ll a , b ,c ; 
            cin >> a >> b >> c ;
            adj[c][a].push_back(b) ; 
            adj[c][b].push_back(a) ; 
        }
        ll q ; cin >> q ; 
        for(ll i = 0; i< q ; i ++){
            ll x , y ; 
            cin >> x >> y ;
             
             ll ans  = 0 ;
             for(ll k = 1 ; k < 101 ; k ++){ 
                vector<bool> v(101 , 0 ) ;
                
             if(dfs(adj[k] , x , y , v ))ans ++ ;  
            }
            cout << ans << endl ; 
        }

    }
    return 0;
}
