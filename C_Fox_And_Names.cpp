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

 int v[26] ;

void dfs( vector<ll> adj[] , ll n , vector<ll>& topo , bool& ans){
    v[n] = 1 ; 
    for(ll child : adj[n] ){
        if(v[child] == 0){
            dfs( adj , child , topo , ans ) ; 
        }else if(v[child] == 1 ){
            ans = 0 ; 
            return ;
        }
    }
    v[n] = 2 ; 
    topo.push_back(n) ;
}
int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        string s[n] ;
        for(ll i = 0 ; i < n ; i ++){
            cin >> s[i] ;  
        }
        vector<ll> adj[26] ;
        bool ans = 1 ; 
         
        ll old = -1  , nw ; 
        for(ll i = 0 ; i < n-1 ; i ++){
            ll l = 0 ; 
            while(l < s[i].size() && l < s[i+1].size() && s[i][l] == s[i+1][l] ){
                l ++ ; 
            }if( l >= s[i+1].size() ){
                ans = 0 ; 
            }else if(l < s[i].size() ){
            adj[(s[i][l] - 'a')].push_back( (s[i+1][l] - 'a') ) ; 
    }
    }
     vector<ll>topo ; 
    for(char i = 'a' ; i <= 'z' ;  i ++){
        ll x = i - 'a' ; 
        if(!v[x]){
            dfs(adj , x , topo , ans ) ; 
        }
    }
    reverse(all(topo)) ; 

    if(ans == 0 )cout << "Impossible" ;
    else{
        for(ll i = 0 ; i < 26 ; i++ ){
            cout << (char)( 'a'+topo[i] ) ;
        }
    }
    }
    return 0;
}
