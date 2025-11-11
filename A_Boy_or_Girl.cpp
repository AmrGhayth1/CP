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

        string s;
        cin >> s;
        set<ll> ss;
        fi(0, s.size())
        {
            ss.insert(s[i]);
        }
        if (ss.size() % 2 == 0)
            cout << "CHAT WITH HER!";
        else
        {
            cout << "IGNORE HIM!";
        }
    }
    return 0;
}
