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
#define endl "\n"
int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> m >> n >> k;

        ll cnt = 0;
         ll cnt2 = (k * 1e6 ) -1 ;
        fi(0, m)
        {
            fj(0, n)
            {
                if (n % k == 0 && i % 2 == 1)
                {
                    ll y = (cnt2 % k) + 1;
                    cnt2--;
                    if (k % 2 == 1)
                    {
                        if (y == (k / 2)){
                            y++;
                        }
                       else if (y == (k / 2 )+ 1)
                            y--;
                    }
                    cout << y << ' ';
                }
                else
                {
                    cout << (cnt % k) + 1 << ' ';
                    cnt++;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
