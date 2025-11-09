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

int main() {
    // بسم الله
    AMR
    ll t = 1 ;
    cin >> t;
    while (t--) {
     ll n;
        ll k;
        cin >> n >> k;

        map<ll, ll> cs, ct; 
        for (ll i = 0; i < n; ++i) {
            ll x; cin >> x;
            cs[x % k]++;
        }
        for (ll i = 0; i < n; ++i) {
            ll x; cin >> x;
            ct[x % k]++;
        }

        bool ans = true;
        set<ll> s; 
        set<ll> s2;
        for (auto &p : cs) s2.insert(p.first);
        for (auto &p : ct) s2.insert(p.first);

        for (ll r : s2) {
            if (s.count(r)) continue;
            s.insert(r);

            if (r == 0) {
                if (cs[r] != ct[r]) { ans = false; break; }
                continue;
            }
            if (k % 2 == 0 && r == k / 2) {
                if (cs[r] != ct[r]) { ans = false; break; }
                continue;
            }

            ll r2 = (k - r) % k;
            if (r2 == r) {
                if (cs[r] != ct[r]) { ans = false; break; }
                continue;
            }

            ll ssum = cs[r] + cs[r2];
            ll tsum = ct[r] + ct[r2];
            if (ssum != tsum) { ans = false; break; }

            s.insert(r2);
        }

        if(ans){
            cout << "YES\n" ;
        }else{
            cout << "NO\n" ; 
        }
    }
    return 0;
}
