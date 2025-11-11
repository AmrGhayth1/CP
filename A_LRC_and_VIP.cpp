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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;
        bool T = 1;
        for (ll i = 1; i < n; ++i)
        {
            if (a[i] != a[0])
            {
                T = 0;
                break;
            }
        }

        if (T)
        {
            cout << "No" << endl;
            continue;
        }

        cout << "Yes" << endl;
        ll x = *max_element(all(a));
        fi(0, n)
        {
            if (a[i] == x)
            {
                cout << 1 << ' ';
            }
            else
            {
                cout << 2 << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
