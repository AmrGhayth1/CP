#include <bits/stdc++.h> 
using namespace std;
#define ll long long
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
        ll n , m ; 
        cin >> n >> m ; 
        ll a[n] ; 
        ll b[n] ; 
        fi(0,n)cin >> a[i] ;
        fi(0,m)cin >> b[i] ;
        vector<ll> v ;
        ll mx = 0 ; 
        fi(0,n){
            mx = max(mx , a[i] ) ; 
            v.push_back(mx) ; 
        }
        reverse(all(v)) ;
        fi(0,n){
            if()
        }
    }
    return 0;
}
