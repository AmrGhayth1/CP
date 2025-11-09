#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    int current = 0;
    int x = n / 2, y = n / 2;
    if (n % 2 == 0) {
        x--;
        y--;
    }
    grid[x][y] = current++;
    int dir = 0; 
    int step = 1;
    while (current < n * n) {
        for (int i = 0; i < 2 && current < n * n; ++i) {
            for (int j = 0; j < step && current < n * n; ++j) {
                switch (dir) {
                    case 0: y++; break;
                    case 1: x++; break;
                    case 2: y--; break;
                    case 3: x--; break;
                }
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    grid[x][y] = current++;
                }
            }
            dir = (dir + 1) % 4;
        }
        step++;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

    return 0;
}
