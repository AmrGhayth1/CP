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
#define shay_blbn  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 +7 ; 
int main()
{
    shay_blbn

        ll n ; cin >> n ; 
        map<pair<ll,ll>,ll> a ; 
        ll ans = 0 ; 
        while(n --){
            ll x1 , y1 , x2 , y2 ; 
            cin >> x1 >> y1 >> x2 >> y2 ; 
            for(ll i = x1 ; i <= x2 ; i ++ ){
                for(ll j = y1 ; j <= y2 ; j ++){
                    ll x = ++ a[{i,j}]  ;  
                    ans = max(ans , x );
                }
            }
        }
        cout << ans ;
    return 0;
}
