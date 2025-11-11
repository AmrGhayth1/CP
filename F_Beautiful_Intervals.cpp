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
next:
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n, 0);
        vector<ll> p(n), pref(n, 0);
        iota(all(p), 0);
        vector<bool> can(n + 1, 1), R(n + 1, 0), L(n + 1, 0);

        for (ll i = 0; i < m; i++)
        {
            ll l, r;
            cin >> l >> r;
            if (r == l)
            {
                can[r - 1] = 0;
            }
            if (r != l)
            {
                L[l - 1] = 1;
                R[r - 1] = 1;
            }
            l--;
            a[l]++;
            if (r < n)
                a[r]--;
        }
        ll sm = 0;

        for (ll i = 0; i < n; i++)
        {
            sm += a[i];
            pref[i] = sm;
        }
        // answer == 0
        for (ll i = 0; i < n; i++)
        {
            if (pref[i] == m)
            {
                swap(p[0], p[i]);
                for (ll &i : p)
                    cout << i << ' ';
                cout << endl;
                goto next;
            }
        }
        // answer == 1
        for (ll i = 0; i < n; i++)
        {
            if (can[i])
            {
                if (i != n - 1 && R[i] == 0)
                {
                    swap(p[1], p[i + 1]);
                    if (i)
                        swap(p[0], p[i]);

                    for (ll &i : p)
                        cout << i << ' ';
                    cout << endl;
                    goto next;
                }
                if (i != 0 && L[i] == 0)
                {
                    swap(p[0], p[i]);
                    if (i != 1)
                        swap(p[1], p[i - 1]);

                    for (ll &i : p)
                        cout << i << ' ';
                    cout << endl;
                    goto next;
                }
            }
        }
        // answer == 2
        swap(p[1], p[2]);
        for (ll &i : p)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
