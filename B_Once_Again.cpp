#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll a[n];
        ll ans = 0;
        map<ll , ll> f ; 
        for (ll &x : a)
            cin >> x;
        map<ll,ll> y ; 
        for (ll i = 0; i < n; i++)
        {
            f[a[i]] ++ ;
            for(ll j = 0 ; j < n ; j ++){
                if(a[j] < a[i] )y[a[i]] ++ ; 
            }
        }
        map<ll,ll> z ; 
     for (ll i = 0; i < n; i++)
        {
            f[a[i]] ++ ;
            for(ll j = 0 ; j < n ; j ++){
                if(a[j] < a[i] )y[a[i]] ++ ; 
            }
        }
        for (ll i = 0; i < n; i++)
        {
            ll eq = f[a[i]] * (m-1) + y[a[i]]  +  ; 
        }
        cout << ans ;
    }
    return 0;
}
