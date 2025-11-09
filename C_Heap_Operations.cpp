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
        ll n;
        cin >> n;
        string ch;
        ll op = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pr;
        vector<pair<string, ll>> ans;
        fi(0, n)
        {
            cin >> ch;
            if (ch == "insert")
            {
                ll x;
                cin >> x;
                pr.push(x);
                ans.push_back({"insert", x});
            }
            else if (ch == "removeMin")
            {
                if (!pr.empty())
                {
                    pr.pop();
                    ans.push_back({"removeMin", -1});
                }
                else
                {
                    ans.push_back({"insert", 1});
                    ans.push_back({"removeMin", -1}) ;
                }
            }
            else if (ch == "getMin")
            {
                ll y;
                cin >> y;
                while (!pr.empty() && y > pr.top() )
                {
                    pr.pop();
                    ans.push_back({"removeMin", -1});
                }
                if (  pr.empty()  ||  y < pr.top()  )
                {
                    ans.push_back({"insert", y});
                    pr.push(y) ;
                }
                ans.push_back({"getMin", y});
            }
        }
        ll sz = ans.size();
        cout << sz << endl;
        fi(0, sz)
        {
 
            cout << ans[i].first;
            if(ans[i].first != "removeMin" ){
                cout << ' '<< ans[i].second ;
            }
            cout << endl ;
        }
    }
    return 0;
}