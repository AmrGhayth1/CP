#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
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
  ll b[n] ;
  fi(0,n){
 cin >> a[i];
  }
  fi(0,n){
 cin >> b[i];
  }
  ll ans = 0;
  fi(0,n-1){

    ll x = a[i]-b[i+1] ;
    if(x > 0)ans += x ;
  }
  ans += a[n-1] ;
  cout << ans << endl ;
       } 
    return 0;
}
