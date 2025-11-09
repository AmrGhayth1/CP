#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define Yara                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    Yara
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        map<ll, ll> m;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        bool b = 0;
        for (ll i = 0; i < n; i++)
        {
            if (m[a[i]] >= 2)
            {
                b = 1;
                break;
            }
        }
        if (b == 0)
        {
            cout << 0 << endl;
            continue;
        }
        vector<ll> one;
        vector<ll> sum;
        for (ll i = 0; i < n; i++)
        {
            if (m[a[i]] % 2 == 1)
            {
                one.push_back(a[i]);
                m[a[i]] = 2;
            }
            else
            {
                sum.push_back(a[i]);
            }
        }
        ll mx = 0;
        if (!one.empty())
        {
            mx = *max_element(one.begin(), one.end());
        }
        sort(all(one));
        ll ans = 0;
        for (ll i = 0; i < sum.size(); i++)
        {
            ans += sum[i];
        }
        ll mx2 = mx;
        for (ll i = 0; i < (ll)(one.size() - 1); i++)
        {
            if ((mx - one[i]) < (ans / 2))
            {
                mx2 = max(mx2, mx + one[i]);
            }
        }
        if (mx >= ans)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ans + mx2 << endl;
        }
    }
    return 0;
}
