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
        ll n, m, k;
        cin >> n >> m >> k;
        bool ans = 1;
        ll a[n];
        fi(0, n)
        {
            cin >> a[i];
        }

        fi(0, n - 1)
        {
            if (a[i] - a[i + 1] >= k)
            {
                m += min((a[i] - (a[i + 1] - k)), a[i]);
            }
            else
            {
                m -= max((a[i + 1] - k) - a[i] , -a[i] );  
            }
            if (m < 0)
            {
                ans = 0;
                break;
            }
            //cout << m << ' ';
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
