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
   // cin >> t;
    while (t--)
    {
        ll n ;
        cin >> n;
        string s[n] ;
        map<string,ll> fq ;
        fi(0,n){
            cin >> s[i] ;
        }
        for(ll i = n-1 ; i >= 0 ; i --){
            if(fq[s[i]] == 0){
                cout << s[i] << endl ;
            }
            fq[s[i]] ++ ;
        }
       } 
    return 0;
}
