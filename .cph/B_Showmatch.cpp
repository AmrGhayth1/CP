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
typedef unsigned __int128 bl;

int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        n *= 2;
        ll a[n];
        fi(0, n) cin >> a[i];
        sort(a, a + n);
        bool ans = 1;
        fi(1, n - 1)
        {
            if (i % 2 == 1)
            {
                if (a[i] - a[i - 1] > a[i + 1] - a[i])
                {
                    ans = 0;
                    break;
                }
            }
            else if (i % 2 == 0)
            {
                if (a[i] - a[i - 1] < a[i + 1] - a[i])
                {
                    ans = 0;
                    break;
                }
            }
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
