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
    // cin >> t;
    while (t--)
    {
        ll mm, n;
        cin >> mm >> n;
        pair<ll, ll> p[n - 1];
        ll x, y;
        cin >> x >> y;
        map<ll, ll> mp;
        fi(0, n - 1)
        {
            cin >> p[i].first >> p[i].second;
        }
        ll count1 = 0;
        ll mx = 0 ;
        fi(0, n-1)
        {
            if (x != p[i].first && x != p[i].second)
            {
                mp[p[i].first]++;
                mp[p[i].second]++;
                count1++;
            mx = max( mp[p[i].first], mp[p[i].second] ) ;
            }
         
        }
        if(mx == count1 ){
            cout << "YES" ;
            return 0 ;
        }
        map<ll, ll> m;
        ll count2 = 0;
        ll mxx = 0 ;
        fi(0, n - 1)
        {
            if (y != p[i].first && y != p[i].second)
            {
                m[p[i].first]++;
                m[p[i].second]++;
                count2++;
                mxx = max(m[p[i].first], m[p[i].second]) ;
            }
        }
         if(mxx == count2 ){
            cout << "YES" ;
            return 0 ;
        }
        cout << "NO";
    }
    return 0;
}
