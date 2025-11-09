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
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 +7 ; 
ll n, m;
vector<char> C = {'a', 'e', 'i', 'o', 'u'};
vector<char> V = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
string s;
int dp[501][25][501][2] ; 
ll dfs( int i, int numC, int numV, bool state)
{
    if(numC > sqrt(n) )return 0 ; 
    if (dp[i][numC][numV][state] != -1)
    {
        return dp[i][numC][numV][state];
    } 
    if ((numC + numV) == n)
    {
        return (numC * numC <= numV && i == m);
    }
    int res = 0;
    for (char y : V)
    {
         int j = i;
        if (i < m && y == s[i])
            j++;
        res = (res % MOD + dfs( j, numC, numV + 1, 0) % MOD) % MOD;
    }
    if (state == 0)
    {
        for (char y : C)
        {
              int  j = i;
            if (i < m && y == s[i])
                j++;
            res = (res % MOD + dfs( j, numC + 1, numV, true) % MOD) % MOD;
        }
    }
    return dp[i][numC][numV][state] = res;
}
int main()
{
    AMR
    
        cin >> n >> m;
        cin >> s;
        memset(dp , -1 , sizeof(dp) ) ; 
        cout << dfs( 0, 0, 0, 0);
    return 0;
}