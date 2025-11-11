#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, r;
        cin >> n >> r;
        set<ll> s ;
        fi(0,n){
            ll x ;
            cin >> x  ;
            s.insert(x) ;
        }
        ll ans = 0 ;
        ll push = 0 ;
        for(auto it = s.rbegin() ; it != s.rend() ; it ++ ){
           if( (*it - push) <= 0)break ;
            push += r ;
            ans ++ ; 
            
        }
        cout << ans << endl ;
    }
    return 0;
}
