#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mpll map<ll, ll>
#define PI pair<int, int>
#define Pll pair<ll, ll>
#define VI vector<int>
#define Vll vector<ll>
#define X first
#define Y second
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define fk(jj, n) for (ll k = jj; k < n; k++)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);
int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int lcm(int a, int b) { return (a * b) / __gcd(a, b); }
double EPS = 1e-9;
#define endl "\n"

/*All rights reserved to
 █████╗ ███╗   ███╗██████╗      ██████╗ ██╗  ██╗ █████╗ ██╗   ██╗████████╗██╗  ██╗
██╔══██╗████╗ ████║██╔══██╗    ██╔════╝ ██║  ██║██╔══██╗╚██╗ ██╔╝╚══██╔══╝██║  ██║
███████║██╔████╔██║██████╔╝    ██║  ███╗███████║███████║ ╚████╔╝    ██║   ███████║
██╔══██║██║╚██╔╝██║██╔══██╗    ██║   ██║██╔══██║██╔══██║  ╚██╔╝     ██║   ██╔══██║
██║  ██║██║ ╚═╝ ██║██║  ██║    ╚██████╔╝██║  ██║██║  ██║   ██║      ██║   ██║  ██║
╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝     ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚═╝  ╚═╝
Hey brother don't copy the code
*/
int main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        ll n ;
        cin >> n;
      mpll m ;
       ll a[n] ;
       ll ss = 0;
       fi(0,n){
    cin >> a[i] ;
    m[a[i]] ++ ;
      if(m[a[i]] == 1)ss ++ ; 
       }
       
      ll x = ss ;
       fi(0,n){
        if(i>=x)ss++;
        cout <<ss<<' ';
       }
     
     
cout << endl ;

    }
    
    return 0;
}