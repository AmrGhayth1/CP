#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    // بسم الله
    AMR
        // freopen("foot.in", "r", stdin);
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        map<string, ll> m;
        vector<string> s(n - 1);
        string me;
        ll tg;
        cin >> me >> tg;
        for (ll i = 0; i < n - 1; i++)
        {
            ll y;
            cin >> s[i] >> y;
            m[s[i]] = y;
        }
        ll q;
        cin >> q;
        map<string, bool> v;
        bool their = 0;
        while (q--)
        {
            string a, b;
            cin >> a >> b;
            if (a == me)
            {
                their = 1;
                v[b] = 1;
                m[b] += 3;
            }
            else if (b == me)
            {
                their = 1;
                v[a] = 1;
                m[a] += 3;
            }
            else
            {
                m[a] += 3;
                m[b] += 3;
            }
        }
        if (their)
        {
            tg += 3;
        }
        bool ans = false;
        sort(all(s), [&](string a, string b)
             { return m[a] > m[b]; });

        if (tg > m[s[0]])
        {
            ans = true;
        }
        else if (v[s[0]])
        {
            ll s0 = m[s[0]] - 3;
            ll s1;
            if (s.size() > 1)
                s1 = m[s[1]];
            else
                s1 = -1;
            if (tg > s0 && tg > s1)
                ans = true;
        }
        if (ans)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
