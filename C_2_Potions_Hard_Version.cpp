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
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll sum = 0;
        ll ans = 0;
        priority_queue<ll> min;
        fi(0, n)
        {
            ll x;
            cin >> x;
            if ((sum + x) >= 0)
            {

                ans++;
                sum += x;
                if (x < 0)
                    min.push(abs(x));
            }
            else if (!min.empty())
            {
                if (abs(x) < min.top())
                {
                    sum += (min.top() + x);
                    min.pop();
                    min.push(abs(x)) ;
                }
            }
        }
        cout << ans;
    }
    return 0;
}
