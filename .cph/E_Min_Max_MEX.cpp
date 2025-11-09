#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
#define endl "\n"
bool fn(ll a[] , ll n , ll x , ll k){
    vector<ll> v(n+1 , 0 ) ; 
    ll cnt1 = 0 , cnt2 = 0  ;  
    fi(0,n){
        if( a[i] < x && v[a[i]] == 0 ){
            v[a[i]] ++ ; 
            cnt1 ++ ; 
        }
        if(cnt1 == x ){
            fj(0,x){
                v[j] = 0 ; 
            }
            cnt2 ++ ; 
            cnt1 = 0 ; 
          if(cnt2 == k )return 1 ;   
        }
    }
    return 0 ; 
}
int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {        
        ll n , k ;
        cin >> n >> k;
        ll a[n] ; 
        fi(0,n)cin >> a[i] ; 
         
        ll l = 0 , r = n ;
        ll ans = 0 ; 
        while(l <= r){
            ll md = (l+r)/2 ; 
            if(fn( a , n , md , k )){
                ans = md ; 
                l = md +1 ; 
            }else{
                r = md-1 ; 
            }
        }
        cout << ans << endl ;
    }
    return 0;
}
