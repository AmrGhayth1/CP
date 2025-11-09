#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n, s;
        cin >> n >> s;
        ll ans = 0;
        for (ll i = 0; i < n; ++i) {
            ll dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            if (dx == -1 && dy == -1 && x == y) {
                ans++;
            } else if (dx == -1 && dy == 1 && x + y == s) {
                ans++;
            } else if (dx == 1 && dy == -1 && x + y == s) {
                ans++;
            } else if (dx == 1 && dy == 1 && x == y ) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
