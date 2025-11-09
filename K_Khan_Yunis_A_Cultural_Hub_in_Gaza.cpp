#include <bits/stdc++.h>
using namespace std;
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

constexpr ld pi = 3.14159265358979323846L;

typedef unsigned __int128 bll;
int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        ld x1, y1, r1;
        ld x2, y2, r2;
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
        ld d = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
        if (d >= (r1 + r2))
        {
            cout << -1;
            return 0;
        }
        if (abs(r1 - r2) > d || d == 0)
        {
            cout << -1;
            return 0;
        }

        if (r1 < r2)
        {
            swap(r1, r2);
        }

        ld ang = 2 * acos((d * d + r2 * r2 - r1 * r1) / (2 * d * r2));
        ld beta = 2 * acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));

        ld area = 0.5 * r2 * r2 * (ang - sin(ang)) + 0.5 * r1 * r1 * (beta - sin(beta));
        ld ans = pi * r1 * r1 - area;

        cout << fixed << setprecision(20) << ans << endl;
    }
    return 0;
}
