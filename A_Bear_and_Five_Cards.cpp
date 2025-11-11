#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
#define endl "\n"
int main()
{
    AMR
    ll t = 1 ;
 //  cin >> t;
    while (t--)
    {
        ll sm = 0 ; 
        map<ll , ll> m ; 
        ll ans = 0 ;
        fi(0,5){
            ll x ; 
            cin >> x ; 
            m[x] ++ ; 
            sm += x ; 
         if( m[x] >= 2  && m[x] <= 3){
         ans = max(ans , x * m[x] ) ; 
         }
        }
        cout << sm - ans ;
    }
    return 0;
}
