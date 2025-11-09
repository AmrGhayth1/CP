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

int main()
{
    // بسم الله
    AMR
        ll t = 1;
    cin >> t;
    next :
    while (t--)
    {
        ll n , k ; 
        cin >> n >> k ; 
        vector<ll> a(n) ; 
        for(ll & y : a)cin >> y ; 
        sort(all(a)) ; 
        ll r = n-1 ; 
        ll l = 0 ; 
        ll sm = 0 ; 
        vector<ll> ans ; 
        ll tt = 0 ; 
        for(ll l = 0 ; l < n ; l ++){
            while( r > l &&  (ll)((sm+a[r])/k) >(ll)((sm)/k) ){
                ans.push_back(a[r]) ;
                tt += a[r] ;  
                sm += a[r] ; 
                r -- ; 
            }
            if(((sm+a[l])/k) >(ll)((sm)/k) ){
                tt += a[l] ; 
            }
            ans.push_back(a[l]) ; 
            sm += a[l] ; 
            if(l >= r)break;
        } 
        cout << tt << endl ; 
        for(ll i : ans)cout << i << ' ' ;
        cout << endl ; 
    }
    return 0;
}
