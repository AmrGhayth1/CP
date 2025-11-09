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
typedef unsigned __int128 bll;

int main()
{
    AMR
        ld x1 = 0,
           x2 = 0, x3 = 0, x4 = 0;

    ld r11 = 50, r12 = 2, r13 = -31, r14 = 6;
    ld r41 = 1, r42 = -3, r43 = 2, r44 = -55;
    ld r21 = 3, r22 = 51, r23 = 2, r24 = 1;
    ld r31 = 2, r32 = 24, r33 = 33, r34 = 3;
    ld a1 = 190, a4 = 60, a2 = 80, a3 = 60;
    ld mn = 1e10;
    while (mn >= 0.01 )
    {
        ld nx1 = (a1 - r12 * x2 - r13 * x3 - r14 * x4) / r11;
       ld e1 = abs((nx1 - x1) / nx1 * 100 );
        x1 = nx1;

        ld nx2 = (a2 - r21 * x1 - r23 * x3 - r24 * x4) / r22;
        ld e2 = abs((nx2 - x2) / nx2 * 100) ;
        x2 = nx2;

        ld nx3 = (a3 - r32 * x2 - r31 * x1 - r34 * x4) / r33;
        ld e3 =  abs((nx3 - x3) / nx3  * 100) ;
        x3 = nx3;

        ld nx4 = (a4 - r42 * x2 - r43 * x3 - r41 * x1) / r44;
        ld e4 =  abs((nx4 - x4) / nx4 * 100 ) ;
        x4 = nx4;
    
        mn = max( e1 , max( e2 , max(e3 , e4))   ) ; 
 cout << x1 << ' ' << x2 << ' '<< x3 << ' '<< x4 << ' '<< mn << endl;

    }
    return 0;
}
