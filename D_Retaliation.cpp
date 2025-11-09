#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
         ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (n == 2) {
            ll nx = 2 * a[1] - a[0];
            ll ny = 2 * a[0] - a[1];
            if (nx >= 0 && ny >= 0 && nx % 3 == 0 && ny % 3 == 0) {
                ll x = nx / 3;
                ll y = ny / 3;
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            ll tt = n * n - 1;
            ll ny = n * a[0] - a[n-1];
            ll nx = n * a[n-1] - a[0];
            if (ny % tt != 0 || nx % tt != 0) {
                cout << "NO" << endl;
            } else {
                ll y = ny / tt;
                ll x = nx / tt;
                if (x < 0 || y < 0) {
                    cout << "NO" << endl;
                } else {
                    bool ans = 1;
                    for (ll i = 1; i < n-1; ++i) {
                        ll val = x * (i+1) + y * (n - i);
                        if (val != a[i]) {
                            ans = 0;
                            break;
                        }
                    }
                    if(ans){
                        cout << "YES" << endl ;
                    }else{
                        cout << "NO" << endl ;
                    }
                }
            }
        }
    }
    return 0;
}
