#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR ios::sync_with_stdio(0); cin.tie(0);

const ll MOD = 1e9 + 7;
ll W[37];
ll n, t;
pair<ll, pair<ld, ld>> p[10005];
ld dp[10005][1005];

ld dfs(ll i, ll time) {
    if (i >= n) return 0;
    if (dp[i][time] != -1) return dp[i][time];

    ld res = 0;
    if (time + p[i].second.first <= t) {
        res = max(res, dfs(i + 1, time + p[i].second.first) +
                  (p[i].second.second * (W[p[i].first] / 100.0L)));
    }
    res = max(res, dfs(i + 1, time));
    return dp[i][time] = res;
}

int main() {
    AMR
    cin >> n >> t;
    for (ll i = 0; i < 36; i++) {
        cin >> W[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second.first >> p[i].second.second;
        p[i].first -= 1;
    }
    for(ll i = 0 ; i< n ;i ++){
        for(ll j = 0 ; j <= t ; j++)dp[i][j] = -1 ; 
    }

    cout << fixed << setprecision(6) << dfs(0, 0) << endl;
    return 0;
}
