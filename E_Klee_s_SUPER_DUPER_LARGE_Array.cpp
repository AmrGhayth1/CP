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
        ll n, k;
        cin >> n >> k;
        n -- ; 
        ll b = ((k - 1) * k) / 2;
        ll sm = (((k + n + 1) * (k + n)) / 2) - b;

        auto fn = [&](ll x)
        {
            ll z = (((k + x + 1) * (k + x)) / 2) - b;
            return ((sm - 2 * z) > 0);
        };
        ll l = 0,
           r = n;
        ll tg;
        while (l <= r)
        {
            ll md = (l + r) / 2;
            if (fn(md))
            {
                l = md + 1;
                tg = l;
            }
            else
            {
                r = md - 1;
            }
        }
         //cout << tg << endl ;
        ll z = ((((k + tg + 1) * (k + tg)) / 2) - b);
        ll op1 = abs(sm - 2 * z);
        tg -- ; 
         z = ((((k + tg + 1) * (k + tg)) / 2) - b);
        ll op2 = abs(sm - 2 * z);
        cout << min(op1, op2) << endl;
    }
    return 0;
}
