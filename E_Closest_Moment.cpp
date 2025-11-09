#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;
const ll MOD = 1e9 + 7;

int main() {
    AMR
    ll t;
    cin >> t;
    while (t--) {
        ld xs, ys, xg, yg, as, bs, ag, bg;
        cin >> xs >> ys >> xg >> yg >> as >> bs >> ag >> bg;

        ld tl = sqrt((xg - xs) * (xg - xs) + (yg - ys) * (yg - ys));
        ld al = sqrt((ag - as) * (ag - as) + (bg - bs) * (bg - bs));
        ld v1x = (xg - xs) / tl, v1y = (yg - ys) / tl;
        ld v2x = (ag - as) / al, v2y = (bg - bs) / al;

        vector<ld> c = {0, tl, al};

        auto add = [&](ld r0x, ld r0y, ld vx, ld vy, ld l, ld r) {
            ld vsq = vx * vx + vy * vy;
            if (vsq == 0) return;
            ld tt = -(r0x * vx + r0y * vy) / vsq;
            if (tt >= l && tt <= r)
                c.push_back(max(l, min(r, tt)));
        };

        add(xs - as, ys - bs, v1x - v2x, v1y - v2y, 0, min(tl, al));
        if (tl < al)
            add(xg - as, yg - bs, -v2x, -v2y, tl, al);
        else if (al < tl)
            add(xs - ag, ys - bg, v1x, v1y, al, tl);

        ld ans = 1e18;
        for (ld tt : c) {
            ld px = tt >= tl ? xg : xs + v1x * tt;
            ld py = tt >= tl ? yg : ys + v1y * tt;
            ld qx = tt >= al ? ag : as + v2x * tt;
            ld qy = tt >= al ? bg : bs + v2y * tt;
            ans = min(ans, (px - qx) * (px - qx) + (py - qy) * (py - qy));
        }
        cout << fixed << setprecision(15) << sqrt(ans) << endl ;
    }
}
