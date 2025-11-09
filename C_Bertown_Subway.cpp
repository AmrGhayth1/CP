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

void dfs(ll v , vector<ll> adj[] , vector<bool>& vis ,ll d , ll & dep ){
    if(vis[v] == 1 )return ; 
    vis[v] = 1 ; 
    dep = max(dep , d ) ;
    for(ll ch : adj[v]){
        if(vis[ch] == 0){
            dfs(ch , adj , vis , d +1 , dep ) ;
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
        ll n ; cin >> n; 
        vector<ll> adj[n+1] ;
        vector<bool> vis(n+1 , 0) ;
        vector<ll> cyc ;
        for(ll i = 1 ; i <= n ; i ++){
            ll x ; cin >> x ; 
            adj[i].push_back(x) ;
        }
        for(ll i = 1; i<= n ;i ++){
            if(vis[i] == 0){
                ll dep = 0 ; 
                dfs(i , adj , vis , 1 ,  dep ) ;
                //cout << i << ' '<< dep << endl ; 
                cyc.push_back(dep) ; 
            }
        }
        sort(all(cyc) , greater<ll>() ) ; 
        ll ans ; 
        if(cyc.size() >= 2 ){
            ans = pow( (cyc[0] + cyc[1] ), 2) ;
        }else{
            ans = pow(cyc[0] , 2) ; 
        }
        for(ll i = 2 ; i < cyc.size() ; i ++){
            ans += pow(cyc[i] , 2) ; 
        }
        cout << ans ; 
    }
    return 0;
}
