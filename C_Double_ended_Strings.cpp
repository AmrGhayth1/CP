#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define fk(kk, n) for (ll k = kk; k < n; k++)
#define AMR ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    AMR
        ll t = 1;
     cin >> t;
    while (t--)
    {
        string x, y;
        vector<ll> a;

        cin >> x >> y;

        ll nx = x.size();
        ll ny = y.size();
        ll ans = 0;
      
      if(x==y){cout << 0 << endl ;}else{
        fi(0, nx)
        {

            fj(0, ny)
            {
                if (x[i] == y[j])
                { 
                    ans = 1;
                    fk(1, min(ny - j, nx - i))
                    {
                        if (x[i + k] == y[j + k])
                        {
                            ans++ ;
                        }
                        else
                        {
                            a.push_back(ans);
                            break;
                        }
                        if(k == (ny-j-1) || k == (nx-i-1)){a.push_back(ans); }
                    }
                }
            }
        }if(ans >0)a.push_back(ans); 
        if (a.empty()){
            cout << nx+ny << endl;
        }else
        {
            cout << nx+ny - 2*(*max_element(all(a))) <<endl;
        }
    }}
    return 0;
}
