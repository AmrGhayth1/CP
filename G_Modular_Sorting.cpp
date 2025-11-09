#include <bits/stdc++.h>
using namespace std;
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
bool is(ll a[], ll n, ll m, ll y)
{
    ll mn = 0;
    cout << y << ' ' ; 
    y = gcd(m,y) ;
    if(y != 0 ){
    for (ll i = 0; i < n; i++)
    {
        ll x =  mn - a[i];
        x = (ll)(x / y);
        x *= y ; 
        x = a[i] + x ; 
        cout << x << endl ; 
        a[i] = x;
        mn = x;
    }
}
    for (ll i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            return 0;
    }
    return 1;
}
int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, m, q;
        cin >> n >> m >> q;
        ll a[n];
        for (ll &x : a)
            cin >> x;
        while (q--)
        {
            ll c;
            cin >> c;
            if (c == 1)
            {
                ll x, y;
                cin >> x >> y;
                a[x] = y;
            }
            if (c == 2)
            {
                ll y;
                cin >> y;
                if (is(a, n, m, y))
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}
