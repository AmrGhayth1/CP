#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

bool bn(ll a[] , ll x , ll n , ll k ){
    ll sm = 0 ; 
    fi(0,n){
        sm  += min( x , a[i] ) ; 
    }
    return (sm >= (k*x) ) ; 
}
int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n , k  ; 
        cin >> k >> n ; 
        ll a[n] ;
        fi(0,n)cin >> a[i] ; 
        ll r = 1e12 ; 
        ll l = 1 ; 
        ll ans = 0 ;
        while(l<=r){
            ll md = (l+r)/2; 
            if(bn(a , md , n , k )){
                l = md +1 ;
                ans = max(ans , md)  ;
            }else{
                r = md -1 ; 
            }
        }
        cout << ans ; 
        }
    
    return 0;
}
