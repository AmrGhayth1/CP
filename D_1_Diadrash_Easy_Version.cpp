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
    // بسم الله
    AMR
    ll t = 1;
    cin >> t;

    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<pair<ll, ll>> a(q);
        for (auto &[x, y] : a)
            cin >> x >> y ;
        ll lmt = max(300LL, (n + 1) / 2 + 2);
        ll ans = 0;
        vector<ll> ind(q);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](ll i, ll j) {
            ll x = a[i].second - a[i].first + 1 ; 
            ll y = a[j].second - a[j].first + 1 ; 
            return (x >y) ;  
        });
        for (ll i = 0; i < lmt && i < q; i++)
        {
            ll l = a[ind[i]].first, r = a[ind[i]].second;
            cout << "? " << l << ' ' << r << endl;
            cout.flush();
            ll mex;
           cin >> mex ; 
            ans = max(ans, mex);
        }
        cout << "! " << ans << endl;
        cout.flush();
    }

    return 0;
}
