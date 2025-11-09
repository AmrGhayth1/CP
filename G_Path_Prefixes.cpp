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
map<ll,ll> a ; 
map<ll,ll> b ; 
map<ll,ll> ans ; 
void dfs(ll v , vector<ll> adj[] , vector<ll> pb , ll pf , ll pfb ){
    pfb += b[v] ; 
    pb.push_back(pfb) ;
    pf += a[v] ;
       // cout << v << ' '<< pf << ' '<<  pfb << endl ;
    ll it = upper_bound(all(pb) ,pf ) - pb.begin() ;
    ans[v] = it ;  
    for(ll ch : adj[v]){
        dfs(ch , adj , pb , pf , pfb ) ; 
    }
}

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
         ans.clear() ;
        a.clear() ;
        b.clear(); 
        ll n ; 
        cin >> n ; 
        vector<ll> adj[n+1] ;
        for(ll i = 2 ; i<= n ; i++){
            ll x , y , z ;
            cin >> x >> y >> z ; 
            adj[x].push_back(i) ;
            a[i] = y ; 
            b[i] = z ; 
        }
        vector<ll> pb ; 
        dfs(1 , adj , pb , 0 , 0) ; 
        for(ll i = 2 ; i <= n ; i ++){
            cout << ans[i] -1 << ' ';
        }
        cout << endl ;
    }
    return 0;
}
