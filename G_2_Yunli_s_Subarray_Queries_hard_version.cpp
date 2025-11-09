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

int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k, q;
        cin >> n >> k >> q;

        vector<ll> a(n + 1);
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a[i] = x - i;
        }
        map<ll, ll> m;
        map<ll, ll> fq;
        vector<ll> ans;
        ans.push_back(0);
        ll x = 0;
        for (ll i = 0; i < k; i++)
        {
            m[fq[a[i]]]--;
            fq[a[i]]++;
            m[fq[a[i]]]++;
            x = max(fq[a[i]], x);
        }
        ans.push_back(k - x);
        for (ll i = 1; i <= n - k; i++)
        {
            m[fq[a[i - 1]]]--;
            fq[a[i - 1]]--;
            m[fq[a[i - 1]]]++;
            m[fq[a[i + k - 1]]]--;
            fq[a[i + k - 1]]++;
            m[fq[a[i + k - 1]]]++;
            if (m[x + 1] > 0)
                x++;
            if (m[x] == 0)
                x--;
            ans.push_back(k - x);
        }
        n = ans.size();
        vector<ll> nxt(n + 2, n + 1); 
        {
            vector<ll> st;
            for (ll i = 1; i <= n; ++i)
            {
                while (!st.empty() && ans[i] < ans[st.back()])
                {
                    nxt[st.back()] = i;
                    st.pop_back();
                }
                st.push_back(i);
            }
        }

        const int LOG = 20; 
        vector<vector<ll>> up(LOG, vector<ll>(n + 2, n + 1));
        vector<vector<ll>> sum(LOG, vector<ll>(n + 2, 0));
        vector<vector<ll>> len(LOG, vector<ll>(n + 2, 0));

        for (ll i = 1; i <= n; ++i)
        {
            up[0][i] = nxt[i];
            len[0][i] = nxt[i] - i;
            sum[0][i] = ans[i] * 1LL * len[0][i];
        }
        up[0][n + 1] = n + 1;
        len[0][n + 1] = 0;
        sum[0][n + 1] = 0;

        for (ll k = 1; k < LOG; ++k)
        {
            for (ll i = 1; i <= n + 1; ++i)
            {
                ll mid = up[k - 1][i];
                up[k][i] = up[k - 1][mid];
                len[k][i] = len[k - 1][i] + len[k - 1][mid];
                sum[k][i] = sum[k - 1][i] + sum[k - 1][mid];
            }
        }

        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            r = r - k + 1;
            ll rem = r - l + 1;
            ll ans2 = 0;
            ll node = l;

            for (ll k = LOG - 1; k >= 0; k--)
            {
                if (node > n)
                    break;
                if (len[k][node] <= rem)
                {
                    ans2 += sum[k][node];
                    rem -= len[k][node];
                    node = up[k][node];
                }
            }
            if (rem > 0 && node <= n)
            {
                ans2 += ans[node] * 1LL * rem;
                rem = 0;
            }
            cout << ans2 << endl;
        }
    }
    return 0;
}
