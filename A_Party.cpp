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
void dfs( ll v , vector<ll> adj[] , vector<ll>& d , ll depth ){
    d[v] = depth ; 
    for(ll ch : adj[v] ){
            dfs( ch , adj , d , depth +1 ) ; 
    }
}

int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n ; cin >> n ;
        vector<ll> adj[n+1] ;
        vector<ll> r ;  
        for(ll i = 1 ; i <= n ; i ++){
            ll p ; cin >> p ; 
            if(p == -1 ){
                r.push_back(i) ; 
            }else{
                adj[p].push_back(i) ;
            }
        }
        vector<ll> d(n+1) ;
        for(ll x : r){
            dfs(x , adj , d , 1 ) ;
        }
        ll ans = 0 ;
        for(ll i = 1 ; i <= n ; i ++){
            ans = max(ans , d[i] ) ;
           // cout << i << ' '<< d[i] << endl ; 
        }
        cout << ans ;
    }
    return 0;
}
