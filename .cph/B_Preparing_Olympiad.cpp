#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
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
      ll n , l , r , x ; 
      cin >> n >> l >> r >> x ; 
      ll a[n] ; 
      fi(0,n)cin >> a[i]  ; 
      sort(a, a+n) ; 
      ll ans = 0 ;
      for (ll mask = 0; mask < (1 << n); ++mask) {
        ll sum = 0, bits = 0;
           ll lst = 1e10 ;
          ll mx = 0 ;       
        for (ll i = 0; i < n; ++i) {
            if (mask & (1 << i) ) {
                sum += a[i];
                bits++;
                mx = max(a[i] , mx ) ;
                lst = min(lst , a[i] ) ;  
               // cout << a[i] << ' '; 
            }
        }
        
        if(sum >= l && sum <= r  && (mx-lst) >= x){
          ans ++ ; 
          //cout << "IT" ; 
        }
        //cout << endl ;
    }
    cout << ans ;
    }
    return 0;
}
