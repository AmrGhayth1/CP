#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;
 
const ll MOD = 1e9 + 7;

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
        fi(0, n) cin >> a[i];
        sort(a, a + n);
        vector<ll> con;
        fi(0, n){
            if (i < a[i]) break;
            con.push_back(a[i]);
        }
        reverse(all(con));
        ll sz = con.size();
        ll x = 0;
        ll ans = 0;
        fi(0, sz){
            ll y = (1LL << (n - sz + i) );
            ll m = (y - x) % MOD;
            ll d = (con[i] + 1) % MOD;
            ans = (ans + m * d % MOD) % MOD;
            x = y;
        }
        cout << ans << endl;
    }
    return 0;
}