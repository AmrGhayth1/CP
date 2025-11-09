#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define AMR ios::sync_with_stdio(0); cin.tie(0);

ll n, x;
vector<ll> c, h;
bool dp[51][50001];

void dfs(ll i, ll happ, ll coins) {
    if (i == n){
        
    }
    if (dp[i][happ]) return;
    dp[i][happ] = true;

    // Option 1: Buy if possible
    if (coins >= c[i]) {
        dfs(i + 1, happ + h[i], coins - c[i] + x);
    }

    // Option 2: Skip
    dfs(i + 1, happ, coins + x);
}

int main() {
    AMR
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        c.resize(n);
        h.resize(n);
        for (ll i = 0; i < n; i++) cin >> c[i] >> h[i];
        memset(dp, 0, sizeof(dp));
        dfs(0, 0, 0);

        ll ans = 0;
        for (ll i = 50000; i >= 0; i--) {
            for (ll j = 0; j < n; j++) {
                if (dp[j][i]) {
                    ans = i;
                    goto done;
                }
            }
        }
    done:
        cout << ans << '\n';
    }
    return 0;
}
