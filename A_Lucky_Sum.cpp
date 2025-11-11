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
ll tl (ll x){
    string s = to_string(x)  ;
    fi(0,s.size()){
        s[i] = '4' ; 
    }
    return stoll(s) ;
}

ll tn(ll x){
    string s = to_string(x)  ;
    bool T = 0 ; 
    for(ll i = s.size()-1 ; i >= 0 ; i--){
        if(s[i] < '7' ){
             if(s[i] < '4'){
            s[i] = '4' ;
             }else{
                s[i] = '7' ; 
             }
             T = 1 ; 
            break; 
        }
    }
    if(!T){
        s.push_back('4') ; 
        fi(0,s.size())s[i] = '4';
    }
    return stoll(s) ;
}
int main()
{
    AMR
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        ll l , r ; 
        cin >> l >> r ;
        ll x = tl(l) ;  
        while(l > x){
            x ++ ; 
            x = tn(x) ; 
        }
        ll ans = 0 ; 
        while(x < r ){
            ll sg = 
            ans += (ll)(min(x-l) , (r-x) )* x ; 
            l = x ; 
            x++ ; 
            x = tn(x) ; 
        }
        cout << ans ; 
    }
    return 0;
}
