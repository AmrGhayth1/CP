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

        ll a,
        b, c, d;
    cin >> a >> b >> c >> d;

    if (abs(c - d) >= 2 || a + b < max(c, d) * 2)
    {
        cout << -1;
        return 0;
    }
    string s;

    if (c > d)
    {
        fi(0,c)
        {
            s.push_back('4');
            s.push_back('7');
        }
    }
    else if(c == d){
     
     if(a >= c+1){
         fi(0,c)
        {
            s.push_back('4');
            s.push_back('7');
        }
      
            s.push_back('7');
            s.push_back('4');
     }else{
         fi(0,d)
        {
            s.push_back('7');
            s.push_back('4');
        }
        s.push_back('4') ;
        s.push_back('7') ;
     }
    }
    else{
        fi(0,d)
        {
            s.push_back('7');
            s.push_back('4');
        }
    }
    string ss;
    ss.push_back(s[0]) ; 
    fi(1, s.size())
    {
        if (s[i - 1] != s[i])
            ss.push_back(s[i]);
    }
    ll a1 = 0, b1 = 0;
    fi(0, ss.size())
    {
        if (ss[i] == '4')
            a1++;
        if (ss[i] == '7')
            b1++;
    }
    a = a -a1;
    b = b -  b1;
    if (b < 0 || a < 0)
    {
        cout << -1;
        return 0;
    }
    ll f = 0, l = 0;
    bool t = 1;
    fi(0, ss.size())
    {
        if (ss[i] == '4' && t)
        {
            f = i;
            t = 0;
        }
        if (ss[i] == '7')
        {
            l = i;
        }
    }
  //  cout << ss << endl; 
    fi(0, ss.size())
    {
        cout << ss[i];
        if (i == f)
        {
            while (a--)
            {
                cout << '4';
            }
        }
        if (i == l)
        {
            while (b--)
            {
                cout << '7';
            }
        }
    }
    return 0;
}
