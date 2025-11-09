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
        pair<ll,ll> a[n] ; 
        ll  ans = n*m*4 ;
        fi(0,n){
            cin >> a[i].first >> a[i].second ;
            if(i >=1){
              ans-=2*(m-a[i].first+m-a[i].second);
          }}
        
     
       cout << ans << endl ;
    }
    return 0;
}
