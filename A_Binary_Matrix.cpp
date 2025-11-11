#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
        ll n, m;
        cin >> n >> m;
        ll ans1 = 0, ans2 = 0;
        string a[n];
        fi(0, n)
        {
            ll cnt = 0;
            cin >> a[i] ; 
            fj(0, m)
            {
                if (a[i][j] == '1')
                    cnt++;
            }
            if (cnt % 2 == 1)
            {
                ans1++;
            }
           
        }
        fi(0, m)
        {
            ll cnt = 0;
            fj(0, n)
            {
                if (a[j][i] == '1')
                    cnt++;
            }
            if (cnt % 2 == 1)
            {
                ans2++;
            } 
        //cout << ans1 << ' '<< i << ' '<< cnt  << endl ; 
        }
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}
