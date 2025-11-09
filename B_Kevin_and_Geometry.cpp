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
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        map<ll, ll> f;
        vector<ll> a;
        ll count = 0;
        vector<ll> v;
        ll aa[n] ;  

        fi(0, n)
        {
            cin >> aa[i];
            f[aa[i]]++;

            if (f[aa[i]] == 2)
            {
                count++;
                a.push_back(aa[i]);
                f[aa[i]] = 0;
            }
        }
        fi(0,n){
            if(f[aa[i]] == 1 ){
                v.push_back(aa[i]) ;
            }
        }

        if (count == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            if (count >= 2)
            {
                cout << a[1] << ' ' << a[1] << ' ' << a[0] << ' ' << a[0] << endl;
            }
            else if (count == 1)
            {
                sort(all(v));
                ll mn = v[0];
                ll mx = v.back();
                for (ll i = n - 1; i > 0; i--)
                {
                    if ((f[v[i]] == 1 && f[v[i - 1]] == 1 && v[i]!=v[i-1] )|| (v[i] == v[i-1] && f[v[i]] == 2))
                    {
                        ll dif = abs(v[i] - v[i - 1] );
                        if (dif < a[0] * 2)
                        {
                            cout << a[0] << ' ' << a[0] << ' ' << v[i-1] << ' ' << v[i] << endl;
                            break;
                        }
                    }
                    if (i == 1)
                    {
                        //fi(0,v.size())cout  << v[i] <<' ';
                        cout << -1 << endl;
                    }
                }
            }
        }
    }
    return 0;
}