#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
#define endl "\n"
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ;
        ll a[n] ;
       
        ll x = 0 ;
        ll ans = 0 ;  
        fi(0,n){
            cin >> a[i] ;
            ll cnt =0 ; 
            ll mx = a[i] ; 
            fj(0,i){
                if(a[j] <= a[i] )cnt ++ ;
                mx = max(a[j] , mx ) ; 
            }
            cout << mx + cnt <<' ';
            ans = max(ans , mx + cnt ) ; 
        } 
        
        cout << ans << endl ;
    }
    return 0;
}