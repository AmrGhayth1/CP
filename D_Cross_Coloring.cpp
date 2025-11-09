#include <bits/stdc++.h>
using namespace std;

#define ld long double

struct Point {
    int x, y, z;
};

ld dist(const Point &a, const Point &b) {
    return sqrt((ld)(a.x - b.x) * (a.x - b.x)
              + (ld)(a.y - b.y) * (a.y - b.y)
              + (ld)(a.z - b.z) * (a.z - b.z));
}

int main() {
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }

    ld ans = 1e18;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ld d1 = dist(p[0], p[i]);
            ld d2 = dist(p[0], p[j]);
            ld d3 = dist(p[i], p[j]);
            ans = min(ans, (d1 + d2 + d3) / 2);
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}
