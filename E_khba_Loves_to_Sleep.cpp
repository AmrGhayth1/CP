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
        ll n, k, X;
        cin >> n >> k >> X;
        vector<ll> a(n);
        for (ll &i : a)
            cin >> i;
        sort(all(a));
        priority_queue<pair<ll, ll>> p;
        map<ll, bool> used;
        for (ll i = 0; i < n; i++)
        {
            if (used[a[i]] == 0)
            {
                p.push({0, a[i]});
                used[a[i]] = 1;
            }
            if (i == 0)
            {
                if (used[0] == 0)
                {
                    p.push({a[i], 0});
                    used[0] = true;
                }
            }
            if (i == n - 1)
            {
                if (used[X] == 0)
                {
                    p.push({X - a[i], X});
                    used[X] = 1;
                }
            }
            if (i == n - 1)
                continue;
            ll nx = a[i + 1];
            ll rng = (nx - a[i] - 1) / 2;
            ll ptr = rng + a[i] + 1;
            if (used[ptr] == 0)
            {
                p.push({min(ptr - a[i], a[i + 1] - ptr), ptr});
                used[ptr] = 1;
            }
            if ((nx - a[i] - 1) % 2 == 0)
            {
                if (used[ptr - 1] == 0)
                {
                    p.push({min(ptr - a[i], a[i + 1] - ptr), ptr - 1});
                    used[ptr - 1] = 1;
                }
            }
        }

        while (k)
        {
            auto [x, y] = p.top();
            p.pop();
            cout << y << ' ';
            k--;
            ll nx = y + 1;
            ll prev = y - 1;
            if (nx <= X)
            {
                if (used[nx] == 0)
                {
                    p.push({x - 1, nx});
                    used[nx] = 1;
                }
            }
            if (prev >= 0)
            {
                if (used[prev] == 0)
                {
                    p.push({x - 1, prev});
                    used[prev] = 1;
                }
            }
        }

        cout << endl;
    }
    return 0;
}
