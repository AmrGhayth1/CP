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
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        ll a[n] ; 
        for(ll &x : a)cin >> x ; 
        ll sm = 0 , ans = 0  ;  
       ll  l = 1 ; 
        for(ll i = 0 ; i < n ; i ++){
            l = 1 ; 
            sm = 0 ; 
            for(ll j = i ; j < n ; j ++){

                sm += a[j] ;

                l = lcm(l , a[j] ) ;

                if(l > 1e12)break; 

              if(sm % l == 0 )ans ++ ;       
          }
           
        }
        cout << ans  << endl ;
    }
    return 0;
}
