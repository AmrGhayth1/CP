#include <bits/stdc++.h>
using namespace std;
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
        ll n ; 
        cin >> n ; 
        ll a[n] ; 
        ll pf[n] ; 
        ll mx = -1e18 ;  
        for(ll i = 0 ; i < n ; i ++){
            cin >> a[i] ;
        }
        ll ans = 0 ; 
        for(ll i = 0 ; i < n ; i ++){
            mx = max(a[i] , mx ) ;
            if(i % 2 == 1){
                    a[i] = mx ; 
            }
        }
         for(ll i = 0 ; i < n ; i ++){
            mx = max(a[i] , mx ) ;
            ll nx = (i == n-1 ) ? 1e18 : a[i+1] ; 
            ll prev = (i == 0) ? 1e18 : a[i-1] ;
            if(i % 2 == 0){
            ll mn = min(prev , nx) ; 
            if(mn <= a[i]){
                ans += a[i] - mn +1 ;
            }
        }
    }
        cout << ans << endl ; 
    }
    return 0;
}
