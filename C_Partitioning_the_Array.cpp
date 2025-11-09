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
        ll n;
        cin >> n;
        ll a[n];
        for (ll &y : a)
            cin >> y;
        vector<ll> div;
        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ll op1 = i;
                ll op2 = n / i;
                div.push_back(op1);
                if (op1 != op2)
                    div.push_back(op2);
            }
        }
        ll ans = 0;
        for (ll d : div)
        {
            ll g = 0;
            for (ll i = 0; i < d; i++)
            {
                for (ll j = i; (j + d) < n; j += d)
                {
                    g = gcd(g, abs(a[j] - a[j + d]));
                }
            }
            if (g != 1)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
