#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld unsigned long double
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
   cin >> t;
    while (t--)
    {
        ll n , m , k ; 
        cin >> n >> m >> k ;
        ll x =((k / n)) ;
        if(x*n < k )x ++ ;   
        ll y = m - x ;
        y ++ ; 
        ll ans = x / y ; 
        if(ans * y < x ) ans ++ ;
        cout << ans << endl ;  
    }
    return 0;
}
