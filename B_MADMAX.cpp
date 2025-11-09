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
#define AMR ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dp[105][105][2][32];
vector<vector<ll>> adj(1000);
map<pair<ll, ll>, ll> mp;
// max_node == 0 || lucas_node = 1
bool rec(ll max_node, ll lucas_node, bool pos, int lst_char) {
    int& mem = dp[max_node][lucas_node][pos][lst_char];
    if (mem != -1) return mem;
    bool moved = false;
    if(!pos){
       for (ll ch : adj[max_node]) {
            if (lst_char <= mp[{max_node, ch}]) {
                moved = true;
                if(rec(ch, lucas_node, 1 - pos, mp[{max_node, ch}]) == 0) {
                    return mem=0;
                } else mem = 1;
            }
        }
    } else {
        for (ll ch : adj[lucas_node]) {
            if (pos && lst_char <= mp[{lucas_node, ch}]) {
                moved = true;
                if(rec(max_node, ch, 1 - pos, mp[{lucas_node, ch}]) == 1) {
                    return mem=1;
                } else mem = 0;
            }
        }
    }
    
    if(!moved) mem = 1 -pos;
    return mem;
}

int main() {
    AMR
    ll t = 1;
    //cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;

        for (ll i = 0; i < m; i++) {
            ll x, y;
            char a;
            cin >> x >> y >> a;
            adj[x].push_back(y);
            mp[{x, y}] = (a - 'a');
        }
        memset(dp, -1, sizeof(dp));
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                 if (rec(i, j, 0, 0)) {
                     cout << 'B';
                 }  else {
                    cout << 'A';
                }
            }
            cout << endl;
        }
    }

    return 0;
}
