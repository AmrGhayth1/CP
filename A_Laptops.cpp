#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    AMR
        ll n;
    cin >> n;
    pair<ll,ll> p[n] ;
    bool T = 0;
    fi(0, n)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p,p+n) ;
    fi(1,n){
        if( p[i].first > p[i-1].first ){
            if(p[i].second < p[i-1].second){
                T = 1 ;
                break;
            }else{
                T = 0 ;
            }
        }
    }
    

    if (T)
    {
        cout << "Happy Alex";
    }
    else
    {
        cout << "Poor Alex";
    }

    return 0;
}
