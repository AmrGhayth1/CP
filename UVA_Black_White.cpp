#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mpll  map<ll, ll>
#define PI pair<int, int>
#define PLL pair<ll, ll>
#define VI vector<int>
#define VLL vector<ll>
#define X first
#define Y second
#define all(a) a.begin(), a.end()
#define fi(ii, n) for (ll i = ii; i < n; i++)
#define fj(jj, n) for (ll j = jj; j < n; j++)
#define fk(jj, n) for (ll k = jj; k < n; k++)
#define clr(arr, val) memset(arr, val, sizeof(arr))
int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int lcm(int a, int b) { return (a * b) / __gcd(a, b); }
double EPS = 1e-9;
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        int av;int played;int scored;int matches;
        cin>>av>>scored>>played>>matches;
        if(matches==0){
            if(av==scored/played){
                cout<<0<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            cout<<38*av-scored<<endl
        }

    }
    return 0;
}
