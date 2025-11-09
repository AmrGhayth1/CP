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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;

int main()
{
    AMR
        ll n;
    cin >> n;
    set<ll> s;
    s.insert(0);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        auto it = s.lower_bound(x);
        ll r = (it != s.end()) ? *it : 0;
        auto ip = prev(it);
        ll l = *ip;
        ll op;
        if (l == 0)
            op = (it != s.end()) ? (r - l) : 0;
        else
        {
            ll pl = *prev(ip);
            op = (it != s.end()) ? min(l - pl, r - l) : (l - pl);
        }
        ll os = 0;
        if ((it != s.end()))
        {
            auto in = next(it);
            os = (in == s.end() ? r - l : min(r - l, *in - r));
        }
        ll np;
        if (l == 0)
            np = x - l;
        else
        {
            ll pl = *prev(ip);
            np = min(l - pl, x - l);
        }
        ll ns = 0;
        if ((it != s.end()))
        {
            auto in = next(it);
            ns = (in == s.end() ? r - x : min(r - x, *in - r));
        }
        ll nx = (it != s.end()) ? min(x - l, r - x) : (x - l);
        ans += (np - op) + nx + ((it != s.end()) ? (ns - os) : 0);
        s.insert(x);
        cout << ans << endl;
    }
}
