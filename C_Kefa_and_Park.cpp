#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;
 vector<ll> adj[200003] ;  
 vector<bool> vis(2000005,0) ; 
void dfs(ll node){
    vis[node] = true ; 
    for(ll child : adj[node] ){
        if(vis[child] == 0 ){
            dfs(child) ; 
        }
    }
    cout << node << ' '; 
}
int main()
{
    // بسم الله
    AMR
        ll t = 1;
   // cin >> t;
    next :
    while (t--)
    {
        ll n,k; 
        cin >> n >> k; 
        vector<bool> cat(n+1 , false);
        for(ll i=0;i<n;i++) {
            bool b;
            cin>>b
            cat[i+1]=b;
        }
        for(ll i = 0 ; i < n -1 ; i ++){
            ll x, y ; 
            cin >> x >> y ; 
             adj[x].push_back(y) ; 
             adj[y].push_back(x) ; 
        }
        dfs(1) ; 
        

    }
    return 0;
}
