#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll int
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
        ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<vector<ll>> a(n);
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            ll m;
            cin >> m;
            a[i].resize(m);
            for (ll j = 0; j < m; j++)
                cin >> a[i][j];
            v[i] = i;
        }

        sort(v.begin(), v.end(), [&](ll i, ll j)
             { return a[i] < a[j]; });

        vector<ll> ans;
        ll ptr = 0;
        for (ll idx : v)
        {
            if (a[idx].size() > ptr)
            {
                for (ll j = ptr; j < a[idx].size(); j++)
                    ans.push_back(a[idx][j]);
                ptr = a[idx].size();
            }
        }

        for (ll x : ans)
            cout << x << ' ';
        cout << endl;
    }
}
