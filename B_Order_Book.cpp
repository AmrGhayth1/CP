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
#define AMR                  \
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
    AMR
        ll n,
        k;
    cin >> n >> k;
    Vll s;
    Vll b;
    mpll ms;
    mpll mb;
    ll ns = 0;
    ll nb = 0;
    fi(0, n)
    {
        char ss;
        ll x, y;
        cin >> ss >> x >> y;
        if (ss == 'S')
        {
            if (ms[x] == 0)
            {
                s.push_back(x);
                ms[x] = y;
            }
            else
            {
                ms[x] += y;
            }
        }
        else
        {
            if (mb[x] == 0)
            {
                b.push_back(x);
                mb[x] = y;
            }
            else
            {
                mb[x] += y;
            }
        }
    }
    sort(s.begin(), s.end() ) ;

    sort(b.begin(), b.end() ) ;

    if (!s.empty())
    {
                ll l1 = min(k , (ll)s.size()) ;
        for (ll i = l1 - 1; i >= 0; i--)
        {
            cout << "S " << s[i] << ' ' << ms[s[i]] << endl;
        }
    }
    if (!b.empty())
    {
        ll l = min(k , (ll)b.size() ) ;
        fi(0, l)
        {
            cout << "B " << b[b.size() - 1 - i] << ' ' << mb[b[b.size() - 1 - i]] << endl;
        }
    }

    return 0;
}
