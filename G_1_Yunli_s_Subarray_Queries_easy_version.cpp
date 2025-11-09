#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
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
        ll n, k, q;
        cin >> n >> k >> q;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a[i] = x - i;
        }
        map<ll, ll> m;
        map<ll, ll> f;
        vector<ll> ans;
        ll x = 0;
        for (ll i = 0; i < k; i++)
        {
            m[f[a[i]]]--;
            f[a[i]]++;
            m[f[a[i]]]++;
            x = max(f[a[i]], x);
        }
        ans.push_back(x);
        for (ll i = 1; i <= n - k; i++)
        {
            m[f[a[i - 1]]]--;
            f[a[i - 1]]--;
            m[f[a[i - 1]]]++;
            m[f[a[i + k - 1]]]--;
            f[a[i + k - 1]]++;
            m[f[a[i + k - 1]]]++;
            if (m[x + 1] > 0)
                x++;
            if (m[x] == 0)
                x--;
            ans.push_back(x);
        }
       
        while (q--)
        {
            ll l, r;
            cin >> l >> r;
              cout << k - ans[l-1] << endl ;
        }
    }
    return 0;
}
