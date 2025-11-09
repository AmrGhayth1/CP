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
        ll n, k;
        cin >> n >> k;
        ll a[n], b[n];
        fi(0, n) cin >> a[i];
        fi(0, n) cin >> b[i];

        ll x = -1;
        bool p = 1;
        fi(0, n)
        {
            if (b[i] != -1)
            {
                ll c = a[i] + b[i];
                if (x == -1)
                    x = c;
                else if (x != c)
                {
                    p = 0;
                    break;
                }
            }
        }

        if (!p)
        {
            cout << 0 << endl;
        }
        else
        {
            if (x == -1)
            {
                ll l = 0, h = 2 * k;
                fi(0, n)
                {
                    l = max(l, a[i]);
                    h = min(h, a[i] + k);
                }
                if (l > h)
                    cout << 0 << endl;
                else
                    cout << h - l + 1 << endl;
            }
            else
            {
                fi(0, n)
                {
                    if (b[i] != -1)
                    {
                        if (a[i] + b[i] != x)
                        {
                            p = 0;
                            break;
                        }
                    }
                    else
                    {
                        ll t = x - a[i];
                        if (t < 0 || t > k)
                        {
                            p = 0;
                            break;
                        }
                    }
                }
                if (p)
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
            }
        }
    }
    return 0;
}
