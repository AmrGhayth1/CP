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
{ // بسم الله
    AMR
        ll t = 1;
    //cin >> t;
next:
    while (t--)
    {
        ll n,
            A, B;
        cin >> n >> A >> B;
        string s;
        cin >> s;

        vector<ll> pfa(n + 1, 0), pfb(n + 1, 0);
        ll sma = 0, smb = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                sma++;
            }
            else
            {
                smb++;
            }
            pfa[i + 1] = sma;
            pfb[i + 1] = smb;
        }

        ll ans = 0;

        for (ll i = 0; i < n; i++)
        {
            auto it1 = lower_bound(all(pfa), pfa[i] + A);
            if (it1 == pfa.end())
                continue;
            ll ind1 = it1 - pfa.begin();

            auto it2 = upper_bound(all(pfb), pfb[i] + B - 1);
            ll ind2 = (it2 - pfb.begin()) - 1;

            if (ind1 <= ind2)
            {
                ans += (ind2 - ind1 + 1);
            }
        }

        cout << ans << endl;
    }
}
