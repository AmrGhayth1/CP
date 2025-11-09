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
int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        ordered_set<pair<ll,ll>> s ;
        map<ll,pair<ll,ll>> m ; 
        vector<ll> u(n+1 , -1 ) ; 
        vector<ll> a ; 
        for(ll i = 1 ; i < n*2 +1 ; i ++){
            ll x ; 
            cin >> x ; 
            if(u[x] == -1){
                a.push_back(x) ;
                u[x] = i ; 
            }else{
                m[x] = {i , u[x]} ; 
                s.insert({ i , u[x] }) ;
            }
        }
        vector<ll> ans(n+1) ;
        
        for(ll i = 0 ; i < a.size() ; i ++){
            ans[a[i]] = min( (ll)(a.size() - i -1) ,  (ll)(s.order_of_key(m[a[i]])) ) ;
            ans[a[i]] = m[a[i]].first - m[a[i]].second - ans[a[i]]*2 -1 ; 
            s.erase(m[a[i]]) ;  
        }
        for(ll i = 1 ;  i <= n ; i++){
            cout << ans[i] << ' ';
        }
    }
    return 0;
}
