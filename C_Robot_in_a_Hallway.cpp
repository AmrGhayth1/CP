#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR ios::sync_with_stdio(0); cin.tie(0);

int main() {
    // بسم الله
    AMR
    ll t; cin >> t;
    while (t--) {
        ll n, m; 
        cin >> n >> m;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;
        sort(all(a));

        vector<pair<ll,ll>> v(m);
        for (auto &[x,y] : v) cin >> x;
        for (auto &[x,y] : v) cin >> y;
        sort(all(v)); // sort monsters by life value

        multiset<ll> swords(all(a));
        ll ans = 0;

        for (auto &[b, c] : v) {
            auto it = swords.lower_bound(b); // find sword with damage >= b
            if (it == swords.end()) continue; // no sword can kill this monster
            ll sw = *it;
            swords.erase(it); // sword disappears
            ans++;
            if (c > 0) swords.insert(max(sw, c)); // gain new sword
        }

        cout << ans << endl;
    }
    return 0;
}
