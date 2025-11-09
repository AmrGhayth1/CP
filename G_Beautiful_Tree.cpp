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

int main()
{
    // بسم الله
    AMR
        ll t = 1;
    cin >> t;
next:
    while (t--)
    {
        ll n;
        cin >> n;
        ll Arth = n * (n - 1) / 2;
        ll mn = Arth - 1 + n;
        ll mx = (Arth)*n;
        ll tg = -1;
        for (ll i = 0; i <= 1e7; i++)
        {
            ll x = i * i;
            if (x >= mn && x <= mx)
            {
                ll d = x - mn ; 
                if(d == 0 || d > n ){
                    tg = x ; 
                    break;
                }
            }
            if (x > mx)
            {
                if (tg == -1)
                {
                    cout << -1 << endl;
                    goto next;
                }
                break;
            }
        }
        vector<bool> us(n + 1, 0);
        ll dff = mx - tg;
        for (ll i = n - 1; i >= 2 ; i--)
        {
            if (dff == 0)
                break ;
            ll y = dff / i ;
            y = min(y, n - 1) ;
            if( n-y == i )y -- ;       
            dff -= y * i;
            us[i] = 1;
            cout << i << ' ' << n - y << endl;
        }
        for (ll i = 1; i < n; i++)
        {
            if (us[i] == 1)
                continue;
            cout << n << ' ' << i << endl;
        } 
    }
    return 0;
}
