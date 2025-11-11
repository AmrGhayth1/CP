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
        string a, b;
        cin >> a >> b;
        ll x = a.size();
        ll y = b.size();
        ll j = 0;
        bool ans = 1;
        for (ll i = x - 1; i > 0; i--)
        {
            if(a[i] != b.back()){
                ans = 0 ;
                break;
            }else{
                b.pop_back() ;
            }
            while (!b.empty() && b.back() == a[i] && b.back() != a[i - 1])
            {
                b.pop_back();
            }
        }
        if(b.empty()){
            ans = 0 ;
        }
        while(!b.empty()){
            if(a[0] != b.back()){
                ans = 0 ;
                break;
            }
            b.pop_back() ;
        }
        if(ans){
            cout << "YES" << endl ;
        }else{
            cout << "NO" <<endl ;
        }
    }
    return 0;
}
