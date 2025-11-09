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
        ll n;
        cin >> n;
        ll a[n];
        map<ll, ll> fq;
        map<ll, ll> fq2;

        fi(0, n)
        {
            cin >> a[i];
            fq[a[i]]++;
            fq2[fq[a[i]]] += fq[a[i]];
        }
        vector<ll> v;

        fi(0, n)
        {
            //  cout << fq2[fq[a[i]]] <<' ';
            v.push_back(fq2[fq[a[i]]]);
        }
        ll ans = n - *max_element(v.begin(), v.end());
        cout << ans << endl;
    }
    return 0;
}
