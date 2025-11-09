#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
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
   cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll mx = *max_element(a.begin(), a.end());
        ll mn = *min_element(a.begin(), a.end());
        ll mxn = count(all(a) , mx) ; 
        ll tt = 0 ; 
        fi(0,n)tt += a[i] ; 
        if ((mx - mn ) >  k + 1) {
            cout << "Jerry" << endl;
        }else if(mx - mn == k+1 && mxn > 1 ){
            cout << "Jerry" << endl;
        } else {
            if(tt %2 == 0){
                cout << "Jerry" << endl;
            }else{
                cout << "Tom" << endl;
            }
        }
    
    }
    return 0;
}