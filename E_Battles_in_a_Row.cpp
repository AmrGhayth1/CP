#include <bits/stdc++.h>
using namespace std;
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
int n, h, m;
vector<int> a, b;
int dp[3001][3001];
void dfs(int i, int health, int magic)
{
    if (i == n){
         dp[i][health] = magic;
         return ;
    }

    if (dp[i][health] != -1 && dp[i][health] >= magic)
        return;

    dp[i][health] = magic;

    if (health >= a[i])
        dfs(i + 1, health - a[i], magic);

    if (magic >= b[i])
        dfs(i + 1, health, magic - b[i]);
}

int main()
{
    // بسم الله
    AMR
  
        cin >> n >> h >> m;
        a.clear();
        b.clear();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            a.push_back(x);
            b.push_back(y);
        }
        dfs(0, h, m);
        for (int i = n ; i >= 0 ; i--)
        {
            for (int j = 0; j <= 3000; j++)
            {
                if (dp[i][j] >= 0)
                {
                    cout << i;
                    return 0;
                }
            }
        }
    return 0;
}