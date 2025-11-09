#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, mm;
        cin >> n >> mm;
        ll a[n];
        ll b[mm];
        map<ll, ll> m;
        deque<ll> v;
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        ll sm = 0;
        for (ll i = 0; i < mm; i++)
        {
            cin >> b[i];
            m[b[i]]++;
            if (v.size() <= n)
            {
                if (m[b[i]] == 1)
                {
                    v.push_back(b[i]);
                }
            }
        }
        ll ans = 0;
        for (ll i = 0; i < mm; i++)
        {
            for (ll j = 0; j < v.size(); j++)
            {
                // cout << b[i] << ' '<< ans << ' '<< v[j] << endl ;
                if (b[i] == v[j])
                {
                    v.erase(v.begin() + j);
                    v.push_front(b[i]);
                    break;
                }
                ans += a[v[j]-1];
            }
        }
        cout << ans;
    }
    return 0;
}
