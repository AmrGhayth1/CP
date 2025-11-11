#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.size();
        ll x = 0;
        ll max1 = 0;
        ll a1 = 0;
        map<ll, ll> freq1;
        priority_queue<ll> ans1;
        fi(0, n)
        {
            if (s[i] == '(')
            {
                x++;
            }
            else
            {
                x--;
                if (x >= 0)
                {
                    a1 += 2;
                }
            }
            if (x == 0)
            {
                ans1.push(a1);
                freq1[a1]++;
            }
            if (x < 0)
            {
                a1 = 0;
                x = 0;
            }
        }

        ll y = 0;
        ll max2 = 0;
        ll b1 = 0;
        ll b2 = 1;
        map<ll, ll> freq2;
        priority_queue<ll> ans2;

        reverse(s.begin(), s.end());
        fi(0, n)
        {
            if (s[i] == ')')
            {
                y++;
            }
            else
            {
                y--;
                if (y >= 0)
                {
                    b1 += 2;
                }
            }
            if (y == 0)
            {
                ans2.push(b1);
                freq2[b1]++;
            }
            if (y < 0)
            {
                b1 = 0;
                y = 0;
            }
        }
        bool F = ans1.empty();
        bool S = ans2.empty();
        if (F)
        {
            if (S)
            {
                cout << 0 << ' '<<1;
            }
            else
            {
                cout << ans2.top() << ' ' << freq2[ans2.top()];
            }
        }
        else
        {
            if (S)
            {
                cout << ans1.top() << ' ' << freq1[ans1.top()];
            }
            else
            {
                if (ans1.top() >= ans2.top())
                {
                    cout << ans1.top() << ' ' << freq1[ans1.top()];
                }
                else
                {
                    cout << ans2.top() << ' ' << freq2[ans2.top()];
                }
            }
        }
    }
    return 0;
}