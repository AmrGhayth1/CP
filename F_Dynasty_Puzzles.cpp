#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"

int n;
string s[500001];
ll dp[500001][27][27]; // 0..25 letters, 26 = none



ll dfs(int i, int lst, int r) {
    if (i == n) {
        return (lst == r ? 0 : -1000000000);
    }
    ll &ret = dp[i][lst][r];
    if (ret != -1) return ret;
    ll res = -1000000000;

    // take as continuation if matches
    if (lst != 26 && s[i][0]-'a' == lst) {
        res = max(res, dfs(i+1, s[i].back()-'a', r) + (int)s[i].size());
    }

    // skip
    res = max(res, dfs(i+1, lst, r));

    // start new root
    res = max(res, dfs(i+1, s[i].back()-'a', s[i][0]-'a') + (int)s[i].size());

    return ret = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 26, 26) << endl; 
}
