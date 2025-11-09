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

int main() {
    // بسم الله
    AMR
    ll rt, ct, ra, ca;
    cin >> rt >> ct >> ra >> ca; 
    ll n, m, l;
    cin >> n >> m >> l;          
    vector<pair<char,ll>> S(m), T(l);
    for (ll i = 0; i < m; ++i) cin >> S[i].first >> S[i].second;
    for (ll i = 0; i < l; ++i) cin >> T[i].first >> T[i].second;

    auto dir = [&](char ch)->pair<ll,ll>{
        if (ch == 'U') return {-1, 0};
        if (ch == 'D') return {1, 0};
        if (ch == 'L') return {0, -1};  
        if (ch == 'R') return {0, 1};
        return {0,0};
    };

    ll i = 0, j = 0;
    ll remS = (m>0 ? S[0].second : 0), remT = (l>0 ? T[0].second : 0);
    ll x1 = rt, y1 = ct; 
    ll x2 = ra, y2 = ca; 
    ll ans = 0;

    while (i < m && j < l) {
        ll t = min(remS, remT);
        auto v1 = dir(S[i].first);
        auto v2 = dir(T[j].first);

        ll rhsx = x2 - x1;
        ll rhsy = y2 - y1;
        ll ddx = v1.first - v2.first;
        ll ddy = v1.second - v2.second;

        if (ddx == 0 && ddy == 0) {
            if (rhsx == 0 && rhsy == 0) {
                ans += t;
            }
        } else if (ddx == 0) {
            if (rhsx == 0 && ddy != 0 && (rhsy % ddy) == 0) {
                ll s = rhsy / ddy;
                if (1 <= s && s <= t) ++ans;
            }
        } else if (ddy == 0) {
            if (rhsy == 0 && ddx != 0 && (rhsx % ddx) == 0) {
                ll s = rhsx / ddx;
                if (1 <= s && s <= t) ++ans;
            }
        } else {
            if ((rhsx % ddx) == 0 && (rhsy % ddy) == 0) {
                ll sx = rhsx / ddx;
                ll sy = rhsy / ddy;
                if (sx == sy && 1 <= sx && sx <= t) ++ans;
            }
        }

        x1 += t * v1.first;
        y1 += t * v1.second;
        x2 += t * v2.first;
        y2 += t * v2.second;

        remS -= t;
        remT -= t;
        if (remS == 0) {
            ++i;
            if (i < m) remS = S[i].second;
        }
        if (remT == 0) {
            ++j;
            if (j < l) remT = T[j].second;
        }
    }

    cout << ans << endl;
    return 0;
}
