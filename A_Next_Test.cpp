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
    ll n ; 
    cin >> n ;
    ll a[n] ;
    fi(0,n){
        cin >> a[i] ;
    }
    sort(a,a+n) ;
    if(a[0] != 1 ){
        cout << 1 ;
        return 0 ;
    }
    fi(1,n){
    if(a[i] != (a[i-1] +1) ){
        cout << a[i-1]+1 ;
        return 0 ;
    }
    }
    cout << a[n-1] + 1 ;
    return 0;
}
