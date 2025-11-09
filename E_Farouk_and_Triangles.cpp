#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld  double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
int main()
{
    AMR
        ll n,
        q;
    cin >> n >> q;
    vector<pair<ld, ll>> a;
    for (ll i = 0; i < n; i++)
    {
        ld l;
        cin >> l;
        ld h = (sqrtl(3.0) / 2.0) * l;
        a.push_back({h, i + 1});
    }

    sort(all(a));

    while (q--)
    {
        ll d1, d2, d3;
        cin >> d1 >> d2 >> d3;
        ld x = sqrt(d1) + sqrt(d2) + sqrt(d3);
        pair<ld , ll > tg = {x , 0 } ;
        auto it = lower_bound(all(a), tg );
        ll ans = -1;
        if (it != a.end() && abs(it->first - x) <= 1e-7)
            ans = it->second;
        else if (it != a.begin())
        {
            it--;
            if (abs(it->first - x) <= 1e-7 )
                ans = it->second;
        }

        cout << ans << endl;
    }
}
