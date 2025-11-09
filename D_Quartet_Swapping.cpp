#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> od;
        vector<ll> ev;
        if (n % 2 == 1)
        {
            fi(0, n - 1)
            {
                ll x;
                cin >> x;
                if (i % 2 == 0)
                {
                    ev.push_back(x);
                }
                else
                {
                    od.push_back(x);
                }
            }
            bool T = 1 ; 
            ll mn;
            cin >> mn;
            sort(all(ev));
            sort(all(od));
            reverse(all(ev));
            reverse(all(od));
            fi(0, n-1)
            {
                if (i % 2 == 0)
                {
                    cout << ev.back() << ' ';
                    ev.pop_back();
                }
                else
                {
                    cout << od.back() << ' ';
                     if (mn < od.back() && T)
            {
                T =0 ;
                cout << mn << ' ';
            }
                    od.pop_back();
                }
            }
          
    }
        else
        {
            fi(0, n)
            {
                ll x;
                cin >> x;
                if (i % 2 == 0)
                {
                    ev.push_back(x);
                }
                else
                {
                    od.push_back(x);
                }
            }
            sort(all(ev));
            sort(all(od));
            reverse(all(ev));
            reverse(all(od));

            fi(0, n)
            {
                if (i % 2 == 0)
                {
                    cout << ev.back() << ' ';
                    ev.pop_back();
                }
                else
                {
                    cout << od.back() << ' ';
                    od.pop_back();
                }
            }
        }
        cout << endl;
    }
    return 0;
}
