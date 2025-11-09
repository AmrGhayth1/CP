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
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;

int main()
{
    AMR
        ll n,
        m, c;
    cin >> n >> m >> c;
    vector<ll> a(n);
    map<ll, ll> fq;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        fq[a[i]]++;
    }
    vector<ll> v;
    ll sm = 0;
    for (auto &y : fq)
    {
        v.push_back(y.first);
        sm += y.second;
    }
    ll ans = 0;
    vector<ll> pf(2 * v.size() + 5, 0), cnt(2 * v.size() + 50);
    for (ll i = 0; i < 2 * v.size(); i++)
    {
        cnt[i] = fq[v[i % v.size()]];
        pf[i + 1] = pf[i] + cnt[i];
    }

    for (ll j = 0; j < v.size(); j++)
    {
        ll prev = (j - 1 + v.size()) % v.size();
        ll rng = (v[j] - v[prev] + m) % m;
        if (rng == 0)
            rng = m;
        ll tg = pf[j] + c;
        auto it = lower_bound(pf.begin() + j + 1, pf.begin() + j + v.size() + 1, tg);
        ans += rng * (*(it)-pf[j]);
    }

    cout << ans << endl;
    return 0;
}
