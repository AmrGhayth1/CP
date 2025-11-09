#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define endl "\n"
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    AMR
        ll n = 1;
    cin >> n;
    map<string, bool> fq;
    map<string, ll> ind;
    string s1[n];
    string s2[n];
    vector<ll> ans;

    fi(0, n)
    {
        cin >> s1[i] >> s2[i];
        if (fq[s2[i]] == 0)
        {
            fq[s2[i]] = 1 ;
            if (fq[s1[i]] == 0)
            {
                ind[s2[i]] = i;
                ans.push_back(i);
            }
            else
            {
                fq[s2[ind[s1[i]]]] = 0;
                s2[ind[s1[i]]] = s2[i];
                ind[s2[i]] = ind[s1[i]];
            }
        }
        else if (fq[s1[i]] == 0)
        {
            fq[s1[i]] = 1;
        }
    }
    cout << ans.size() << endl;
    fi(0, ans.size())
    {
        cout << s1[ans[i]] << ' ' << s2[ans[i]] << endl;
    }

    return 0;
}
