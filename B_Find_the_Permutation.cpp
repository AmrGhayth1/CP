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
        ll n;
        cin >> n;
        string s[n];
        pair<ll,ll> p[n] ;
        map<ll, bool> m;

        for (ll i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (ll i = n-1; i >= 0; i--)
        {
            ll x = 0;
            for (ll j = 0; j <= i; j++)
            {
                if (s[i][j] == '1')
                    x++  ;
                    if(j == i){
                        //cout << x << ' ';
                p[i].first = x ;
                p[i].second = -(i+1); 
                }
            }
        }
        sort(p,p+n) ;
        for (ll i = 0; i < n; i++)
        {
            cout << abs(p[i].second) << ' ';
        }

        cout << endl;
    }
    return 0;
}