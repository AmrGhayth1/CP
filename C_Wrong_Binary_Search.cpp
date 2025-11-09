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

int main()
{
    // بسم الله
    AMR
        ll t = 1;
    cin >> t;
next:
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> ans(n);
        string s;
        cin >> s;
        ll num = n;
        vector<ll> used(n + 1, false);
        queue<ll> st;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                ans[i] = i + 1;
                used[i + 1] = true;
                st.push(i);
            }
        }

        ll x = n;
        if (!st.empty())
        {
            x = st.front();
        }

        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                while (used[x])
                    x--;
                used[x] = true;
                ans[i] = x;
                x--;
            }
            else
            {
                st.pop();
                if (!st.empty())
                {
                    x = st.front();
                }
                else
                {
                    x = n;
                }
            }
        }
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {

            if (s[i] == '1' && cnt == 1)
            {
                cout << "NO\n";
                goto next;
            }
            if (s[i] == '0')
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
        }
        if (cnt == 1)
        {
            cout << "NO\n";
            goto next;
        }
        cout << "YES\n";
        for (ll &x : ans)
            cout << x << ' ';
        cout << endl;
    }
    return 0;
}
