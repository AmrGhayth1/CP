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
        ll a[n];
        fi(0, n) cin >> a[i];
        vector<ll> bt(31, 0);
        fi(0, n)
        {
            fj(0, 31)
            {
                if ((a[i] & (1LL << j)) == (1LL << j) )
                {
                    bt[j]++;
                }
            }
        }
        ll ans = 0;
       // cout << ( a[1] & 1 )<< endl ; 
        fi(0, n)
        {
            ll ss = 0;
            fj(0, 31)
            {
                if ((a[i] & (1LL << j)) == (1LL << j) )
                {
                    ss += (n - bt[j]) * (1LL << j);
                }
                else
                {
                    ss += (bt[j]) * (1LL << j);
                }
            }
            ans = max(ans, ss);
        }
        cout << ans << endl;
    }
    return 0;
}
