#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bl;

int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string ss;
        cin >> ss;
        ll s = 1, b = n;
        vector<ll> v(n , 0 );
        for(ll i = n-2 ; i >= 0; i -- ){
            if (ss[i] == '>')
            {
                v[i+1] = b ;
                b--;
            }
        }
        fi(0, n )
        { 
            if(v[i] == 0 )
            {
                v[i] = b ;
                b -- ;
            }
        }
        fi(0, n )
        {
            cout << v[i] << ' ';
        }
       // cout << (s + b) / 2;
        cout << endl;
    }
    return 0;
}
