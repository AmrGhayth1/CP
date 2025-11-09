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
        ll n;
        cin >> n;
        ll a[n], b[n];
        vector<ll> ans;
        bool T = 0 ;
        fi(0, n)
        {
            cin >> a[i];
        }
        ll count = 0;
        ll nn = 0;
        fi(0, n) cin >> b[i];
        fi(0, n )
        {
            ll y = i;
            if (a[i] != n-b[i] || n-a[i] != b[i] )
            {
                count++;
                nn = a[i];
            }
        }

        if (count > 1 || (count == 1 && n % 2 == 0))
            T = 1;

        fi(0, n)
        {
            if ((a[i] != i + 1))
            {
                ans.push_back(max(a[i], i + 1));
                ans.push_back(min(a[i], i + 1));
            }
        }
        if (!T){
            if(nn != (n/2)+1 ){
          ans.push_back(max(nn , (n/2)+1) ) ;
          ans.push_back(min(nn , (n/2)+1) ) ;
            }
        }
            if (T)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << ans.size() / 2 << endl;
                fi(0, ans.size())
                {
                    cout << ans[i] + 1 << ' ';
                    if (i == ans.size() - 1)
                        cout << endl;
                }
            }
    }
    return 0;
}
