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
   string ss ;
   cin >> ss ; 
   set<char> s ;
  ll n = ss.size() ;
  ll ans  = 0;
  fi(0,n){
   s.insert(ss[i]) ;
   if(s.size() > 3){
    ans ++ ;
    s.clear() ;
    s.insert(ss[i]);
   }
  }
  if(s.size()!=0)ans ++; 

cout << ans << endl ;
       } 
    return 0;
}
