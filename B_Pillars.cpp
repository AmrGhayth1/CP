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
        ll ind = 0;
    ll mx = 0;
    ll n;
    cin >> n;
    ll a[n];
    fi(0, n)
    {
        cin >> a[i];
        if (a[i] > mx)
        {
            ind = i;
            mx = a[i];
        }
    }
    fi(0, ind)
    {
        if (a[i] > a[i + 1])
        {
            cout << "NO";
            return 0;
        }
    }
    fi(ind + 1, n)
    {
        if (a[i - 1] < a[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" ;

    return 0;
}
