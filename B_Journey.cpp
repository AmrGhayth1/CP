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
   ll a[3] ;
   ll sum = 0; 
   fi(0,3){
    cin >> a[i] ;
   sum += a[i] ;
   }
   if(n%sum == 0){cout << (n/sum)*3 << endl ;}else{
   ll x = n/sum ;
   ll ss = abs(n - sum*x) ;
   ll s2 = 0 ; 
   
   fi(0,3){
    s2 += a[i] ;
    if(s2 >= ss){
        cout << i + 1 + x*3 << endl ;
        break ;  
    }
   }
   }
       } 
    return 0;
}
