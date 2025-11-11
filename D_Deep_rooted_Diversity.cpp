#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bl;


int main()
{
    AMR
    ll t = 1 ;
  // cin >> t;
    while (t--)
    {
        ll n ;
        cin >> n ; 
        ll a[n] , d[n] ; 
        fi(0,n)cin >> a[i] ; 
        fi(0,n){
            ll x ; 
            cin >> x ; 
            d[i] = a[i] - x ; 
        } 
        sort(d ,d +n) ;
        reverse(d ,d+n) ;  
        ll ans = 0 ;
        ll sm = 0 ;  
        fi(0,n){
            sm += d[i] ; 
            if(sm >= 0 ){
                ans ++ ; 
            }else{
                break;
            }
        }
        cout << ans ;
    }
    return 0;
}
