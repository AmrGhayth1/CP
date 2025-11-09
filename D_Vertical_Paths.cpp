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
void dfs(vector<ll>& vc , vector<bool>& vs , vector<ll> adj[] , ll v  ){
    vs[v] = 1 ; 
    vc.push_back(v) ;
    for(ll c : adj[v] ){
        if(vs[c] == 0 ){
            dfs(vc , vs , adj , c ) ; 
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
        ll n ; 
        cin >> n ; 
        vector<ll> adj[n+1] ; 
        map<ll,ll> m ; 
        for(ll i = 1 ;i <= n ; i ++){
            ll x; 
             cin >> x ; 
             adj[i].push_back(x) ;
             m[x] ++ ;
        }
        vector<ll> lfs ; 
        for(ll i = 1 ; i <= n ; i ++){
            if(m[i] == 0){
                lfs.push_back(i) ; 
            }
        }
        if(lfs.empty()){
            cout << 1 << endl << 1 << endl << 1 << endl ; 
            continue ; 
        }
        vector<bool> vs(n+1 , 0 ) ; 
         cout << lfs.size() << endl ; 
         for(ll i = 0 ; i < lfs.size() ; i++){
            vector<ll> v ; 
            dfs(v , vs , adj  , lfs[i]) ;
            if(!v.empty()){
            cout << v.size() << endl ;
            for(ll i = v.size()-1 ; i >= 0 ; i -- )cout << v[i] << ' ';
            cout << endl ; 
         }
        }

    }
    return 0;
}
