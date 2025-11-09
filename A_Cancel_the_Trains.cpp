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
        ll n , m ;
     cin >> n >>m ;
     map<ll,ll> mp ;
     fi(0,n){
    ll x ;
    cin >> x ;
    mp[x] ++ ;
     }
     ll ans = 0 ;
     fi(0,m){
        ll y ;
        cin >> y ;
        if(mp[y] == 1 )ans++;
    
     }
      cout << ans << endl ;
       } 
    return 0;
}
