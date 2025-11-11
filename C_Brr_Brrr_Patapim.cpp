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
        vector<ll> ans(2 * n - 1 );
        vector<ll> nn(2*n +1 , -1);
        fi(0, n)
        {
            fj(0, n)
            {
                ll x;
                cin >> x;
                ans[j + i] = x;
                nn[x] = 1;
            }
        }
        fi(0, 2*n +1 )
        {
            if (nn[i + 1] == -1)
                cout << i + 1 << ' ';
        }

        fi(0, ans.size()) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}
