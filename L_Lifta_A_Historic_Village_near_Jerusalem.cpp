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
const ll N = 1e7 + 1 ; 
vector<bool> is_prime(N, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
     }
  }
}
void dfs(vector<vector<ll>>& adj , vector<bool>& vis , ll& sn , ll v ){
    vis[v] = 1 ;
    sn ++ ; 
    for(ll ch : adj[v] ){
        if(vis[ch] == 0){
            dfs(adj , vis , sn , ch ) ; 
        }
    } 
}

int main()
{
    AMR
    sieve() ; 
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ;
        vector<vector<ll>> adj(n+1) ; 
        ll ans = (n *(n-1) )/ 2 ;  
        for(ll i = 0 ; i < n ; i ++){
            ll x , y ; 
            cin >> x >> y ; 
            if(is_prime[x] == 0 && is_prime[y] == 0){
                adj[x].push_back(y) ; 
                adj[y].push_back(x) ; 
            } 
        }
        
        vector<bool> vis(n+1 , 0) ; 
        for(ll i = 1 ; i <= n ; i ++){
            if(vis[i] == 0){
                ll sn = 0 ; 
                dfs(adj , vis , sn , i) ;
                ll x =( sn*(sn-1) )/ 2 ; 
                ans -= x ; 
            }
        }
        cout << ans ; 
    }
    return 0;
}
