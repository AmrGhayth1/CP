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

bool sub(set<ll>& s1 , set<ll>& s2){
    map<ll,bool> f  ;
    for(ll x : s2)f[x] = 1 ; 
        for(ll x : s1){
            if(f[x] == 0 )return 0 ; 
        } 
        return 1  ;
}

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n , p ; cin >> n >> p ; 
        vector<set<ll>> b(n+1) ; 
        vector<set<ll>> g(n+1) ; 
        for(ll i = 0 ; i < p ; i ++){
            ll x , y ; 
            cin >> x >> y ; 
            b[x].insert(y) ; 
            g[y].insert(x) ; 
        }
        ll ans = 0 ; 
        for(ll i = 1 ; i <= n ; i ++){
            ll cnt = 0 ; 
          for(ll j = 1 ; j <= n ; j ++){         
            if( i != j && sub(b[i] , b[j] ))cnt ++ ; 
        }
        ans = max(ans , cnt +(ll)(b[i].size()) ) ; 
        }
          for(ll i = 1 ; i <= n ; i ++){
            ll cnt = 0 ; 
          for(ll j = 1 ; j <= n ; j ++){         
            if( i != j && sub(g[i] , g[j] ))cnt ++ ; 
        }
        ans = max(ans , cnt + (ll)(g[i].size() )) ; 
        }
        cout << max(ans+1 , n) << endl ;
    }
    return 0;
}
