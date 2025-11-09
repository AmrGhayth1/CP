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
        ll n,
        k;
    cin >> n >> k;
    deque<pair<ll, ll>> a;
    map<ll, bool> used;
    ll shift = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (used[x])
        {
            shift++;
            continue;
        }
        used[x] = true;
        a.push_back({x, shift});
    }
    while (k--)
    {
        ll x;
        cin >> x;
        for (ll i = 0; i < a.size(); i++)
        {
            if (a[i].first == x)
            {
                cout << i + a[i].second +1 << ' ';
                a.erase(a.begin() + i);
                a.push_front({x, 0});
            }
        }
    }
    return 0;
}
