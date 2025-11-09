#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
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
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        ll ga = 0 ; 
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ga = gcd(ga , a[i]) ; 
        }
        ll gb = 0 ; 
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            gb = gcd( gb , b[i] );

        }
        
        if (ga == gb) {
            cout << 0 << endl ;
            continue;
        }
        

        ll c = gcd(ga, gb);
        ll ap = ga / c;
        ll bp = gb / c ;
        
     
        if (gb % ga == 0 || ga % gb == 0) {
            cout << 1 << endl ;
        } else {
            cout << 2 << endl ;
        }
    }
    return 0;
}
