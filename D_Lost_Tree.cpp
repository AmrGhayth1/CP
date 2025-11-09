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
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
map<ll,bool> us ; 
ll n ;
void fn( vector<pair<ll,ll>>& v , ll j ){
         while(v.size() < n-1 ){
             cout << "? " << j << endl << endl ;
        cout.flush() ; 
        vector<ll> adj[n+1] ; 
        for(ll i = 1 ; i <= n ; i ++){
            ll x ;
            cin >> x ; 
            adj[x+1].push_back(i) ;  
        }
        ll x = 1 ; 
        while(v.size() < n-1  && adj[x].size() == 1 ){
            for(ll ch : adj[x+1]){
                if(us[adj[x][0]] == 0){
                v.push_back({adj[x][0] , ch}) ;
                us[adj[x][0]] = 1 ; 
            }
        }
            x ++ ; 
        }
        if(v.size() < n-1 ){
            for(ll ch : adj[x])fn(v , ch) ; 
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
        cin >> n ; 
        vector<pair<ll,ll>> v ; 
        map<ll,ll> us ; 
        ll times = (n+1)/2  ; 
        fn(v , 1 ) ; 
    cout << "!\n" ; 
    for(auto b : v){
        cout << b.first << ' '<< b.second << endl ; 
    }

}
    return 0;
}