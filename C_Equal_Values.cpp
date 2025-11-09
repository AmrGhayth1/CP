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
        ll n ; cin >>n; 
        ll a[n] ; 
        for( ll &x : a)cin >> x ;
        ll ans = 1e18 ;
        ll l = 1 , r = n ;
        ll b = a[0] ;  
        for(ll i = 0 ; i <n ; i ++){
            if(b == a[i] ){
                r = i+1 ; 
            }else{
                ll x = b*(n-r) + b*(l-1) ; 
                l = i+1 ; 
                r = i+1 ; 
                ans = min(ans , x) ; 
                b = a[i] ; 
            }
            if(i == n-1 ){
                ll x = b*(n-r) + b*(l-1) ; 
                ans = min(ans , x) ; 
            }
        }
        cout << ans << endl ; 
    }
    return 0;
}
