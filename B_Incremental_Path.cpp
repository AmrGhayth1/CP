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
        {
            ll n, m;
            cin >> n >> m;
            string s;
            cin >> s;
            set<ll> B;
            for (ll i = 0; i < m; ++i)
            {
                ll x;
                cin >> x;
                B.insert(x);
            }

            auto W = [&](ll x)
            {
                ll y = x + 1;
                auto it = B.lower_bound(y);
                while (it != B.end() && *it == y)
                {
                    y = *it + 1;
                    it ++ ;
                }
                return y;
            };

            vector<ll> v;
            for (ll i = 1; i <= n; i++)
            {
                if (i == 1)
                {
                    ll y = 1;
                    if (s[0] == 'A')
                        y++;
                    else
                        y = W(1);
                    v.push_back(y);
                    B.insert(y);
                }
                else
                {
                    v.pop_back();
                    ll start;
                    if (v.empty())
                        start = 1;
                    else
                        start = v.back();
                    ll y = start;
                    for (ll k = i - 2; k <= i - 1; ++k)
                    {
                        if (s[k] == 'A')
                            y++;
                        else
                            y = W(y);
                        v.push_back(y);
                    }
                    B.insert(v.back());
                }
            }

            cout << B.size() << endl;
            bool first = true;
            for (ll y : B)
            {
                cout << y << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
