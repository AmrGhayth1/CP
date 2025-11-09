#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR ios::sync_with_stdio(0); cin.tie(0);

int main() {
    // بسم الله
    AMR
    ll t;
    cin >> t;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<ll> v(n);
        ll lst = -1;
        for (ll i = 2 * n - 1; i >= 0; i--) {
            if (s[i % n] == 'B') lst = i % n;
            if (i < n) v[i] = lst;
        }

        while(q --){
            ll x ; 
            cin >> x ; 
            ll ans = 0, i = 0;
            while (x > 0) {
                if (s[i] == 'A') {
                    if (v[i] == -1) {
                        ans += x; 
                        x = 0;
                        break;
                    }
                    ll diff = (v[i] - i + n) % n;
                    if (diff >= x) {
                        ans += x;
                        x = 0;
                        break;
                    }
                    x -= diff;
                    ans += diff;
                    i = v[i];
                } else { 
                    x /= 2;
                    ans++;
                    i = (i + 1) % n;
                }
            }
            cout << ans << endl ;
        }
    }
    return 0;
}
