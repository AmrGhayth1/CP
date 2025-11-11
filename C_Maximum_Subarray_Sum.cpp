#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
typedef  __int128 bll;

int main()
{
    AMR
        ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll a[n];
        bool T = 1;
        fi(0, n)
        {
            ll x;
            cin >> x;
            if (s[i] == '0')
            {
                a[i] = -1e18;
                T = 0;
            }
            else
            {
                a[i] = x;
            }
        }
        ll rr = 0;
        bll tt = 0;
        bll sm = 0;
        bll mx = -1e18;
        fi(0, n)
        {
          if(s[i] == '1'){
            sm += a[i] ; 
            if(sm < 0 )sm = 0 ; 
            mx = max(mx , sm ) ; 
          }else{
            sm = 0 ; 
          }
            tt += a[i];
        }
        if (mx > k || (T && mx != k))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            if (mx == k)
            {
                fi(0, n) cout << a[i] << ' ';
            }
            else
            {
                ll p0 = -1 ;
                fi(0,n){
                    if(s[i] == '0'){
                        p0 = i ; 
                        break; 
                    }
                }
                bll mxl = 0 , mxr = 0 ;
                bll sm = 0 ;  
                fi(p0+1,n){
                    sm += a[i] ;
                    mxr = max(mxr , sm) ;  
                }
                sm = 0 ; 
                for(ll i = p0 - 1 ; i >= 0 ; i --){
                    sm += a[i] ; 
                    mxl = max(mxl , sm ) ; 
                }
                fi(0,n){
                    if(i != p0)cout << a[i] << ' ';
                    else cout << (ll)( k - (mxr + mxl ) ) << ' ';  
                }
               
            }
            cout << endl;
        }
    }
    return 0;
}
