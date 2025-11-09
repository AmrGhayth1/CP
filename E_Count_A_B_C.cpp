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
const ll MOD = 998244353;
ll F(ll N)
{
    ll ans = 0;
    ll l = 1;
    while (l <= N)
    {
        ll q = N / l;
        ll r = N / q;
        ll cnt = (r - l + 1) % MOD;
        ans = (ans + (q % MOD) * cnt) % MOD;
        l = r + 1;
    }
    return ans;
}
int main()
{
    AMR
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll x = 0, y = 0;

        x = (n % MOD) * ((n + 1) % MOD) % MOD;
        x = x * ((MOD + 1) / 2) % MOD;

        y = F(n);

        cout << (x - y + MOD) % MOD << endl;
    }
    return 0;
}

