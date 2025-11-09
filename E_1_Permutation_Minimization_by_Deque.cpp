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

        ll n , x ;
        cin >> n;
       cin >> x ;
        deque<ll> d ;
        d.push_back(x) ; 
        fi(0,n-1){
            ll y ;
            cin >> y ;
            if(y <= d[0] ){
                d.push_front(y) ;
            }else{
                d.push_back(y) ;
            }
        }
        fi(0,n){
            cout << d[i] << ' ';
        }
        cout << endl ;
       
    }
    return 0;
}
