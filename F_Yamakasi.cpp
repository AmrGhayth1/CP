#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

ll cs(const vector<ll>& v, ll target) {
    map<ll, int> m;
    m[0] = 1;
    ll sum = 0, count = 0;

    for (ll num : v) {
        sum += num;
        count += m[sum - target];
        m[sum]++;
    }

    return count;
} 

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n;
        ll s, x;
        cin >> n >> s >> x;

        ll a[n] ; 
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        ll ans = 0;
        vector<ll> b;

        for (int i = 0; i <= n; ++i) {
            if (i == n || a[i] > x) {
                if (!b.empty()) {
                    ll tt = cs(b, s);

                    ll bad = 0;
                    vector<ll> c;

                    for (ll val : b) {
                        if (val == x) {
                            if (!c.empty()) {
                                bad += cs(c, s);
                                c.clear();
                            }
                        } else {
                            c.push_back(val);
                        }
                    }
                    if (!c.empty()) {
                        bad += cs(c, s);
                    }

                    ans += tt - bad;
                    b.clear();
                }
            } else {
                b.push_back(a[i]);
            }
        }

        cout << ans << endl ;
    }
    return 0;
}
