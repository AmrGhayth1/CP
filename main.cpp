#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("../../error.txt", "w", stderr);
    freopen("./output.txt", "w", stdout);
#endif

    fast

    int t;
    cin >> t;
    while (t--) {
        ll k, a, b, c, d;
        cin >> k >> a >> b >> c >> d;

        ll count = 0;

        if (k > c) c = k-1;

        for (ll x = a; x <= b && x <= d; ++x) {
            if (x >= c) {
                count++; 
            }

            ll y = x * k; 
            while (y <= d) {
                if (y >= c) {
                    count++; 
                }
                if (y > d / k) break;
                y *= k; 
            }
        }

        cout << count << '\n';
    }
}
