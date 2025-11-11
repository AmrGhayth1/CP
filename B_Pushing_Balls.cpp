#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        string a[n];
        fi(0, n)
        {
            cin >> a[i] ; 
        }
        bool ans = 1;
        fi(0, n)
        {
            fj(0, m)
            {
                if (a[i][j] == '1')
                {
                    bool r = 0, c = 0;
                    for (ll k = i ; k >= 0; k--)
                    {
                        if (a[k][j] == '0')
                            c = 1;
                    }
                    for (ll k = j; k >= 0; k--)
                    {
                        if (a[i][k] == '0')
                            r = 1;
                    }
                    if (r & c){
                        ans = 0;
                }
            }
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
