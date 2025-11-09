#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        map<ll,ll> m ; 
        ll a[n] ; 
        for(ll i = 0 ; i < n ; i ++){
            cin >> a[i] ; 
            m[a[i]-i] += a[i] ;  
        }
        ll ans = 0 ; 
         for(ll i = 0 ; i < n ; i ++){
           ans = max(ans, m[a[i]-i] ) ; 
        }
        cout << ans ; 
    }
    return 0;
}
