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

    vector<bool> v(60, 0) ;  
void dfs(vector<ll> adj[] , ll x , ll & np ){
    v[x] = 1 ;
    np ++ ;  
    for(ll c : adj[x] ){
        if(!v[c] ){
            dfs(adj , c , np ) ; 
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
        vector<ll> adj[n+1] ; 

        for(ll i = 0 ; i < m ; i ++){
            ll x , y ;cin >> x >> y ;
            adj[x].push_back(y) ; 
            adj[y].push_back(x) ;

        }
        ll ans = 1 ; 
        for(ll i = 1 ; i <= n ; i ++ ){

            ll x =  i ; 
           
            if(!v[x]){
                   ll  np = 0 ;

                dfs(adj , x , np ) ; 
            
            ans *= (1LL << (np-1) ) ; 
        }
    }
        cout << ans ;

    }
    return 0;
}
