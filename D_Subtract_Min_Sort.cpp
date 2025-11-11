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
        vector<int> a(n);
        fi(0, n) cin >> a[i];

        fi(1, n)
        {
            ll d = min(a[i], a[i - 1]);
            a[i] -= d;
            a[i - 1] -= d;
        }

        bool ans = 1;
        fi(1, n)
        {
            if (a[i] < a[i - 1])
            {
                ans = 0;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}
