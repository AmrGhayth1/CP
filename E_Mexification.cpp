#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);

string f(vector<ll> &a)
{
    string s;
    for (auto x : a)
    {
        s += to_string(x);
        s.push_back(',');
    }
    return s;
}

vector<ll> g(vector<ll> &a)
{
    ll n = a.size();
    vector<ll> c(n + 2);
    for (auto x : a)
        c[x]++;
    set<ll> z;
    for (ll i = 0; i <= n; i++)
        if (c[i] == 0)
            z.insert(i);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    {
        ll v = a[i];
        c[v]--;
        bool y = 0;
        if (c[v] == 0)
        {
            z.insert(v);
            y = 1;
        }
        b[i] = *z.begin();
        if (y)
            z.erase(v);
        c[v]++;
    }
    return b;
}

int main()
{
    AMR
        ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        ll u = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            u += a[i];
        }
        if (k == 0)
        {
            cout << u << endl;
            continue;
        }
        vector<vector<ll>> v;
        map<string, ll> m;
        v.push_back(a);
        m[f(a)] = 0;
        ll p = -1;
        for (ll i = 1; i <= k; i++)
        {
            vector<ll> b = g(v.back());
            string s = f(b);
            if (m.find(s) != m.end())
            {
                ll st = m[s];
                ll len = i - st;
                ll idx = st + (k - st) % len;
                p = idx;
                break;
            }
            else
            {
                m[s] = i;
                v.push_back(b);
            }
            if ((ll)v.size() > k)
            {
                p = k;
                break;
            }
        }
        if (p == -1)
        {
            if ((ll)v.size() > k)
                p = k;
            else
                p = v.size() - 1;
        }
        ll ans = 0;
        for (ll x : v[p])
            ans += x;
        cout << ans << endl;
    }
}
