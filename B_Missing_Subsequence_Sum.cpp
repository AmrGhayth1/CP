#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

int main()
{
    AMR
    ll t = 1 ;
   cin >> t;
    while (t--)
    {
        ll n , k ;
        cin >> n >> k ;
        ll b = log2(k) ;
         b = (1LL<<b)  ; 
         vector<ll> v ; 
        for(ll i = 0 ; i <= 20 ; i ++){
            ll x = (1LL<<i) ; 
                if(x == b ){
                    v.push_back(k-b) ; 
                 break;   
                }else{
                    v.push_back(x) ;
                }                
        }
        
         for(ll i = 0 ; i <= 20 ; i ++){
            ll x = (1LL<<i)+k  ; 
                if(x <= n ){
                    v.push_back(x) ; 
            }else{
                break;
            }
        }

        cout << v.size() << endl; 
        for(ll vl : v ){
            cout << vl << ' ';
        }
        cout << endl ;
    }
    return 0;
}
