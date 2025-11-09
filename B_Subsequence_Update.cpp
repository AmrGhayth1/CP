#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    AMR
    ll t = 1 ;
    cin >> t;

    while (t--) {
        ll n, l, r;
        cin >> n >> l >> r;
        n -- ;
        r -- ;
        ll a[n] ;
        ll sm =  0 ; 
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            if(i>= l && i<= r)sm += a[i] ;
        }
        vector<ll> ans ;
        ans.push_back(sm) ;
        ll j = 0 ; 
        for(ll i = l ; i >= r ; i ++){
         sm -= a[i] ;
         sm += a[j] ;
         j ++ ;
         ans.push_back(sm) ;
        }        
        cout << *max_element(all(ans)) << endl ;
    }

       
    return 0;
}
