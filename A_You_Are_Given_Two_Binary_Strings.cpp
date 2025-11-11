#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
int main()
{
    AMR
        ll t;
    cin >> t;

    while (t--)
    {
        string a, b;
        cin >> a >> b;
        ll cn0 = 0;
        while (!b.empty() && b.back() == '0')
        {
            b.pop_back();
            cn0++;
        }

        ll ans = 0;
        ll x = 0;
        while (!a.empty())
        {
                if (x > cn0)
                {
                  //  cout << a.back()<<' ';
                    ans ++;
                }
             if( x >= cn0 && a.back() != '0' )break;

            x++;
            a.pop_back();
        }
        if (ans < 0)
            ans = 0;
        cout << ans << endl;
    }

    return 0;
}
