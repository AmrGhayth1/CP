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
        ll n , m ; 
        cin >> n >> m ; 
        ll ans = 0 ; 
        m -- ; 
        ll a[n] ; 
        for(ll & y : a )cin >> y ; 
        sort( a , a + n ) ;
        vector<ll> v ; 
        for(ll i = 0 ; i < n ; i ++){
            if(i){
                v.push_back(a[i] - a[i-1]) ; 
            }
        }
        sort(all(v) , greater<ll>()) ; 
        for(ll i = m ; i < v.size() ; i ++){
            ans += v[i] ; 
        }
        cout << ans  ;

    }
    return 0;
}
