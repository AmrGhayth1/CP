#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
const ll MOD = 1e9 + 7;
 
int main()
{
    // بسم الله
    AMR
 
        int r,
        g;
    cin >> r >> g;
 
    int tt = r + g;
    int n = (-1 + sqrt(1 - 4 * (-2 * (tt)))) / 2;
    tt = (n * (n + 1)) / 2;
 
    int dp[400001];
    dp[0] = 1;
 
    for (int i = 1; i <= n; i++)
    {
        for (int sum = tt; sum >= i; sum--)
        {
            dp[sum] = (dp[sum] % MOD + dp[sum - i] % MOD) % MOD;
        }
    }
 
    int ans = 0;
    for (int i = max(0, tt - max(r, g)); i <= min(tt, min(r, g)); i++)
    {
        ans = (ans % MOD + dp[i] % MOD) % MOD;
    }
 
    cout << ans;
 
    return 0;
}