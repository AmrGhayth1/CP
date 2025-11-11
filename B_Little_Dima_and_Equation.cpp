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
ll sum(ll xx)
{
    string x = to_string(xx);
    ll count = 0;
    while (!x.empty())
    {
        count += (x.back() - '0');
        x.pop_back();
    }
    return count;
}
int main()
{
    AMR
        ll a,
        b, c;
    cin >> a >> b >> c;
    vector<ll> ans;
    fi(0, 100)
    {
        ll x = ceil(b * (pow(i, a)) + c);
        if (x >= 1e9)
            break;

        if (i == sum(x) && x > 0)
        {
            ans.push_back(x);
        }
    }
    cout << ans.size() << endl;
    fi(0, ans.size())
    {
        cout << ans[i] << ' ';
    }

    return 0;
}
