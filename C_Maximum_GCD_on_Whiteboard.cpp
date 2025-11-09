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
        vector<ll> v(n+1 , 0 ) ;
        for(ll i = 0 ; i < n ; i ++){
            ll x; 
            cin >> x ; 
            for(ll j = 1 ; j*j <= x ; j ++){
                if(x%j == 0 ){
                    ll op1 = j ; 
                    ll op2 = x/j ; 
                    v[op1] ++ ; 
                    if(op2 != op1)
                    v[op2] ++ ;
                }else{    
                    if(x >= 4*j )
                    v[j] ++ ; 
                }
            }
        }
        ll ans =  1 ; 
        for(ll i = n  ; i >= 1 ; i -- ){
            //cout << i << ' '<< v[i] << endl ; 
            if(v[i] + k >= n  ){
                ans = i ; 
                break;
            }
        }
        cout << ans << endl ;
    }
    return 0;
}
