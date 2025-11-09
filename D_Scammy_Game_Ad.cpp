#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define ll long long
#define dl long double
#define ull unsigned long long
#define F first
#define S second
#define pb push_back
#define endll '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define popcnt(x) __builtin_popcountll(x)
#define debug(x) cerr << #x << ": " << x << '\n';
#define Da3do3a cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
const int N = 2e5+12, mod = 1e9+7;
int t = 1;
int cn=0;
// int dp[]
void solv() {
    int n;
    cin>>n;
    cn++;
    vector<pair<int,char>> in;
    vector<pair<int,char>> in2;
    vector<pair<int,int>> cnt(n+1,{1,1});
    for(int i=0; i<n; i++)
    {
        char o,t;
        int one, two;
        cin>>o>>one;
        cin>>t>>two;
        in.push_back({one, o});
        in2.push_back({two, t});
        if(o=='x') cnt[i].first=one;
        if(t=='x') cnt[i].second=two;
        if(cn==1837)
        {
            cout<<o<<":"<<one<<","<<t<<":"<<two<<",";
        }
    }
    for(int i=n-1; i>=0; i--)
    {
        cnt[i].first *= cnt[i+1].first;
        cnt[i].second *= cnt[i+1].second;
    }
    // for(int i=0; i<n; i++)
    // {
    //     cout<<cnt[i].first<<" "<< cnt[i].second<<"\n";
    // }
    int l=1, r=1;
    for(int i=0; i<n; i++)
    {
        int ne = 0;
        if(in[i].second=='+') ne+=in[i].first;
        else ne += (l*(in[i].first-1));
 
        if(in2[i].second=='+') ne+=in2[i].first ;
        else ne += (r*(in2[i].first-1));
 
        if(cnt[i].first>cnt[i].second)
        {
               l+=ne;
        }
        else if(cnt[i].first<cnt[i].second)
        {
                r+=ne;
        }
        else
        {
            if(l>r) l+=((ne+1)/2), r+=(ne/2);
            else r+=((ne+1)/2), l+=(ne/2);
        }
        // cout<<l<<" "<<r<<" \n";
    }
    cout<<l+r<<"\n";
}
 
int32_t main() {
    Da3do3a
    cin >> t;
    while (t--) solv();
    return 0;
}