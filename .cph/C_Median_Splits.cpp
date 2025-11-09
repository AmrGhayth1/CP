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
        ll n, k;
        cin >> n >> k;
        bool a[n];
        fi(0, n)
        {
            ll x;
            cin >> x;
            a[i] = (k >= x);
        }
        ll cnt = 0;
        ll ind = 0;
        bool ans = 0;
        fi(0, n)
        {
            if (i % 2 == 0)
                ind++;
            if (a[i])
            {
                cnt++;
            }
            if (cnt >= ind && !(i < (n - 1) && a[i + 1] == 0 && (i % 2) == 0))
            {
                cnt = 0;
                ind = 0;
                ll x = -1;
                fj(i + 1, n)
                {
                    x++;
                    if (x % 2 == 0)
                        ind++;
                    if (a[j])
                    {
                        cnt++;
                    }
                    if (cnt >= ind)
                    {
                        ans = 1;
                        // cout << a[i] << ' '<< a[j] << endl;
                        break;
                    }
                }
                break;
            }
        }
        ind = 0;
        cnt = 0;
        fi(0, n)
        {
            if (i % 2 == 0)
                ind++;
            if (a[i])
            {
                cnt++;
            }
            if (cnt >= ind && !(i < (n - 1) && a[i + 1] == 0 && (i % 2) == 0))
            {
                cnt = 0;
                ind = 0;
                ll x = -1;
                for (ll j = n - 1; j > i; j--)
                {
                    x++;
                    if (x % 2 == 0)
                        ind++;
                    if (a[j])
                        cnt++;
                    if (cnt >= ind)
                    {
                        // cout << a[i] << ' '<< a[j] << endl;
                        ans = 1;
                        break;
                    }
                }
                break;
            }
        }
        reverse(a, a + n);
        ind = 0;
        cnt = 0;
        fi(0, n)
        {
            if (i % 2 == 0)
                ind++;
            if (a[i])
            {
                cnt++;
            }

            if (cnt >= ind && !(i < (n - 1) && a[i + 1] == 0 && (i % 2) == 0))
            {
                cnt = 0;
                ind = 0;
                ll x = -1;
                fj(i + 1, n)
                {
                    x++;
                    if (x % 2 == 0)
                        ind++;
                    if (a[j])
                    {
                        cnt++;
                    }
                    if (cnt >= ind)
                    {
                        ans = 1;
                        break;
                    }
                }
                break;
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
