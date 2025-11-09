#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef unsigned __int128 bll;

const ll N = 1e7 + 1;
vector<ll> spf(N);

void sieve()
{
    for (ll i = 0; i < N; i++)
        spf[i] = i;
    for (ll i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<ll> get_factors(ll x)
{
    vector<ll> factors;
    while (x != 1)
    {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

int main()
{
    AMR
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        sieve();
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;
        bool ans = 1;
        map<ll, ll> m;
        set<ll> s;
        for (int i = 0; i < n; i++)
        {
            vector<ll> factors = get_factors(a[i]);
            for (ll f : factors)
            {
                s.insert(f);
                m[f]++;
            }
        }
        for (ll x : s)
        {
            if (m[x] % k != 0)
            {
                ans = 0;
                break;
            }
        }
        if (ans)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    return 0;
}
