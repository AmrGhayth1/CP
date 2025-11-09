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
        cout << "1 1 " << n << endl
             << flush;
        ll sm1;
        cin >> sm1;
        if (sm1 == -1)
            return 0;
        cout << "2 1 " << n << endl
             << flush;
        ll sm2;
        cin >> sm2;
        if (sm2 == -1)
            return 0;
        ll sz = sm2 - sm1;
        ll l = 1, r = n;
        while (l < r)
        {
            ll md = (l + r) / 2;
            cout << "2 1 " << md << endl
                 << flush;
            cin >> sm1;
            cout << "1 1 " << md << endl
                 << flush;
            cin >> sm2;
            ll dff = sm1 - sm2;
            if (dff >= 1)
                r = md;
            else
                l = md + 1;
        }
        cout << "! " << l << ' ' << l + sz - 1 << endl
             << flush;
    }
    return 0;
}
