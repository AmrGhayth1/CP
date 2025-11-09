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
        ll a[n];
        map<ll, ll> fq;
        vector<ll> v;
        fi(0, n)
        {
            cin >> a[i];
            fq[a[i]]++;
            if (fq[a[i]] == 1)
                v.push_back(a[i]);
        }
        bool ans = 0;
        sort(all(v));
        map<ll, bool> p;
        fi(0, v.size())
        {
            if (fq[v[i]] >= 4)
            {
                ans = 1;
                break;
            }
            if (fq[v[i]] >= 2)
            {
                p[v[i] + 2] = 1;
            }
            if (fq[v[i]] == 1)
            {
                if (p[v[i] + 1])
                {
                    p[v[i] + 2] = 1;
                }
            }
            else if (p[v[i] + 1] && p[v[i] + 2])
            {
                ans = 1;
                break;
            }
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
