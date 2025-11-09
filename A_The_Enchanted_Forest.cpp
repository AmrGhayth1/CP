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
    while (t--)
    { ll n;
        ll k;
        cin >> n >> k;
        ll a[n] ; 
        for(ll& y : a)cin >> y ; 

        ll pf[n+1] ; 
        ll sm = 0 ; 
        pf[0] = 0 ;  
        for (ll i = 0; i < n; i++){
            sm += a[i] ;
            pf[i+1] = sm ;  
        }

        if (k >= n) {
            ll ans = sm + (n * k )- (n * (n + 1) / 2 );
            cout << ans << endl ;
            continue; 
        }

            ll x = 0;
            x = pf[k] - pf[0];
            for (ll i = k ; i < n ; i ++ ) {
                ll y = pf[i+1] - pf[i+1-k];
                if (y > x) x = y;
            }
            ll ans = x + k * (k - 1) / 2;
            cout << ans << endl ;
        
    }
    return 0;
}
