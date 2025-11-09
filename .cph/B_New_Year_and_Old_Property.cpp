#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bll;

int main()
{
    AMR
    ll t = 1 ;
 //  cin >> t;
    while (t--)
    {
         ll a , b ; 
        cin >> a >> b ; 
        bll x = 0 ; 
        ll ans = 0 ; 
        fi(0,65){
            x += (bll)(pow(2,i)) ;
            fj(0,i){
                bll y = x - (bll)(pow(2 , j )) ;
                if(y >= a && y <= b){
                  //  cout << (ll)x << ' '<< (ll)(y) << ' '<< j << endl ;
                    ans ++ ; 
                }
            } 
        }
        cout << ans ; 
    }
    return 0;
}
