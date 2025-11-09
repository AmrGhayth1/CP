#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    AMR
    ll t = 1 ;
    cin >> t;
    while (t--) {
        ll n ;
        cin >> n;

        cout << 1 << ' ';
        for (int i = 2; i <= n - 2; i++) {
            cout << i - 1 << ' ';
        }
        cout << 1 <<' '<< 2 << endl;
    }

    return 0;
}
    
