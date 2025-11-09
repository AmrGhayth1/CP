#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a ; 
        a.push_back(0) ; 
        fi(0, n)
        {
            ll v ; 
            cin >> v ;
            a.push_back(v) ;
        }
        a.push_back(0) ; 
        ll ans =  0 ; 
        fi(1,n+1){
            if(a[i] > a[i-1] && a[i] > a[i+1])ans ++ ; 
            if(a[i] > a[i-1] && a[i] >= a[i+1]){
                a[i] -- ; 
            } 
        }
        cout << ans << endl ;
    }
    return 0;
}
