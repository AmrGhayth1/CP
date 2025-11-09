#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef unsigned __int128 bl;


int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n ; 
        cin >> n ; 
        pair<ll,ll> p[n] ; 
        map<pair<ll,ll> , ll> m ; 
        fi(0,n){
            cin >> p[i].first >> p[i].second ; 
            m[ {p[i].first , p[i].second}] = 1 ; 
        }
        ll x = p[0].first , y = p[0].second ; 
        fi(0,n){
            ll a = p[i].first ;
            ll b = p[i].second ; 
            if(m[{a+1,b}] && m[{a , b+1}] && m[{a+1 , b-1 }]){
                 x = a ; 
                y = b ; 
                break;
            }else if( m[{a,b}] && m[{a-1 , b+1}] && m[{a , b-1 }]){
                x = a-1 ; 
                y = b ; 
                break;
            }else if( m[{a+1,b-1 }] && m[{a , b}] && m[{a+1 , b-2 }] ){
                x = a ; 
                y = b-1 ; 
                break;
            }else if(m[{a,b+1}] && m[{a-1 , b+2}] && m[{a , b }]){
                x = a-1 ; 
                y = b+1 ; 
                break;
            }
        }
        cout << x << ' '<< y << endl; 
    }
    return 0;
}
