#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
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
        ll n , m ; 
        cin >> n >> m ;
        string ans ; 
        ll f[n] ; 
        f[0] = 1 ; f[1] =2 ; 
        for(ll i= 2 ; i < n ; i ++){
            f[i] = f[i-1] + f[i-2] ; 
        }
        while(m --){ 
        ll a[3] ; 
        for(ll &x : a){
            cin >> x ; 
        }
    sort(a,a+3) ;
    if(a[2] >= f[n-1] + f[n-2] && (n <= 2 ||  a[1] >= f[n-2] + f[n-3] ) && a[0] >= f[n-1] ){
        ans.push_back('1') ; 
    }else{
                ans.push_back('0') ; 
    }
    }
    cout << ans << endl ;
    }
    return 0;
}
