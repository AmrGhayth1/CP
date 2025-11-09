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
    while (t--)
    {
        ll n , k ;
        cin >> n >> k ;
    pair<ll,ll> p[n] ;
    fi(0,n){
        cin >> p[i].first;
    }
    fi(0,n){
        cin >> p[i].second ;
    }
    sort(p,p+n) ;
    ll s = 1 ;
    
    if(k<n){
       s = p[k].first * (n-k);
    }


    for(ll i = k-1 ; i>=0 ; i --){

      //cout << p[i].first <<' '<<p[i].second; 
        if((p[i].second*(n-i) ) > s){   
            s = (p[i].second)*(n-i) ;

        }
    }
    cout << s << endl ;

          } 
    return 0;
}
