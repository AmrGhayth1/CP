#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        bool T = 0;
        ll n, m;
        cin >> n >> m;
        ll a[n][m];
        ll p[n];
        ll rem;
        fi(0, n)
        {
            fj(0, m)
            {
                cin >> a[i][j];
                ll x = a[i][j] + 1;
                if (j == 0)
                {
                    rem = x % n ;
                    if(rem != 0)
                    p[rem-1] = i + 1;
                    else{
                        p[n-1] = i+1 ;
                    }
                }
                if ( x % n != rem)
                {
                   // cout << x << ' '<<rem << endl ; 
                    T = 1;
                    break;
                }
            }
        }
        if (T)
        {
            cout << -1 << endl;
        }
        else
        {
            fi(0, n)
            {
                cout << p[i] << ' ';
            }
            cout << endl ;
        }
    }
    return 0;
}
