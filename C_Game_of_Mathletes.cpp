#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define AMR ios::sync_with_stdio(0); cin.tie(0);

int main() {
    AMR
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        map<ll, ll> freq;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            if (freq[a[i]] > 0) {
                ll c = k - a[i];
                if (a[i] == c) {
                    ans += freq[a[i]] / 2;
                    freq[a[i]] = 0;
                } else if (freq[c] > 0) {
                    ll pairs = min(freq[a[i]], freq[c]);
                    ans += pairs;
                    freq[a[i]] -= pairs;
                    freq[c] -= pairs;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
