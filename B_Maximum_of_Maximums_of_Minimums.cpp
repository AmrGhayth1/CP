#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n , k ; 
        cin >> n >> k ;
        ll a[n] ;  
        for(ll &x : a )cin >> x ; 
        if( k == 1 )cout << *min_element(a,a+n) ; 
        else if(k >= 3 )cout << *max_element(a,a+n) ;
        else {
            ll x1 = 1e18  , x2 = 1e18 ; 
            ll mx1 = -1e18 , mx2 = -1e18 ; 
            for(ll i = 0 ; i<n ; i ++ ){
                x1 = min(x1 , a[i] ) ; 
                mx1 = max(mx1 , x1 ) ;
            }
              for(ll i = n-1  ; i >= 0  ; i -- ){
                x2 = min(x2 , a[i] ) ; 
                mx2 = max(mx2 , x2 ) ;
            }
            cout << max(mx1 , mx2 ) ; 
        }
    }
    return 0;
}
