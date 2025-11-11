#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mpll map<ll, ll>
#define PI pair<int, int>
#define Pll pair<ll, ll>
#define VI vector<int>
#define Vll vector<ll>
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define fk(jj, n) for (ll k = jj; k < n; k++)
#define AMR                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

int main()
{
    AMR
    ll t = 1 ;
   // cin >> t;
    while (t--)
    {
     int a[3] ;
     fi(0,3)cin >> a[i] ;

     sort(a,a+3) ;
     cout << (a[1]-a[0] )+(a[2]-a[1]) ;

       }
     
     
    return 0;
}
