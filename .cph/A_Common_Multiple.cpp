#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bl;

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        set<ll> s;
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            s.insert(a[i]);
        }
        cout << s.size() << endl;
    }
    return 0;
}
