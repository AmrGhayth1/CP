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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;
        if (s[n - 1] == 'A' && s[0] == 'A')
            ans = 1;
        ll mb = 0;
        ll cnt = 0;
        fi(0, n)
        {
            if (s[i] == 'B')
            {
                mb = i;
                cnt++;
            }
        }
        fi(mb, n - 1)
        {
            if (s[i] == 'A')
                ans = 1;
        }
        if (s[n - 1] == 'B'){
            if(cnt > 1)ans = 0 ; 
            else ans = 1 ; 
        }
        if (ans)
        {
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
    }
    return 0;
}
