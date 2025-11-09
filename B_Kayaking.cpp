#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =  __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
void fn(vector<ll> a , ll i , ll j , ll & sm ){
    ll lst = -1 ; 
    for(ll k = 0 ; k < a.size() ; k ++ ){
        if(k == i || k == j )continue;
        if(lst  == -1 ){
            lst = a[k] ; 
        }else{
            sm += a[k] - lst ; 
            lst = -1 ; 
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
        ll n ; cin >> n ; 
        n *= 2 ; 
        vector<ll> a(n) ;  
        for(ll i = 0 ; i < n ; i ++){
            cin >> a[i] ; 
        }
        sort(all(a)) ;
        ll ans = 1e17 ; 
        ll sm = 0 ; 
        for(ll i = 0 ; i < n-1 ; i ++ ){
            for(ll j = i+1 ; j < n ; j ++){
             ll sm = 0 ; 
             fn( a , i , j , sm ) ; 
                 ans = min(sm , ans ) ; 
            }
        }
        cout << ans ;
    }
    return 0;
}
