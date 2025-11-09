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
   cin >> t;
    while (t--)
    {
        ll n , k ; 
        cin >> n >> k ; 
        ll a[n+1] ;
        a[0] = 0 ;  
        ll sm = 0 ; 
        for(ll i = 1 ; i <= n ; i ++){
            ll x ; cin >> x ; 
            sm += x ; 
            a[i] = sm ; 
        }
        ll ans = 0 ;
        bool T = 1 ; 
        for(ll i = 0 ; i <= n-k ; i ++){
            if(T){
            if(a[i] == a[i+k]){
                ans  ++ ;
                i = i+k -1 ;  
                T = 0 ; 
            }
            }else{
                T = 1 ; 
            }
           // cout << ans << ' ' << T << ' ' << i << endl ; 
    }
    cout << ans << endl ; 
    }
    return 0;
}
