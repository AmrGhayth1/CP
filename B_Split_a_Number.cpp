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

string add(string num1, string num2)
{
    string result = "";
    int carry = 0;
    ll i = num1.size() - 1;
    ll j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        ll digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        ll digit2 = (j >= 0) ? num2[j--] - '0' : 0;

        ll sum = digit1 + digit2 + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    AMR
        ll n;
    cin >> n;
    string s;
    cin >> s;
    ll mid = (n + 1) / 2;
    string s1, s2;
    string sa, sb;
    ll mid1 = mid;
    ll mid2 = mid-1;
    while (mid1 < n && s[mid1] == '0')
        mid1++;
    while (mid2 > 0 && s[mid2] == '0')
        mid2--;
    fi(0, mid1)
    {
        s1.push_back(s[i]);
    }
    fi(mid1, n)
    {
        s2.push_back(s[i]);
    }
    fi(0, mid2)
    {
        sa.push_back(s[i]);
    }
    fi(mid2, n)
    {
        sb.push_back(s[i]);
    }
    string x = add(s1, s2);
    string y = add(sa, sb);


    if (x.size() > y.size())
    {
        cout << y;
    }
    else if (x.size() == y.size())
    {
        cout << min(x, y);
    }
    else
        cout << x;
    return 0;
}
