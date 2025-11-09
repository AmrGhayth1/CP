#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define Yara  ios::sync_with_stdio(0); cin.tie(0);
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int main()
{
    Yara
    ll t = 1 ;
   //cin >> t;
    while (t--)
    {
        
        string s;
        cin>>s;
        bool anylower =0;
        bool alllower=1;
        if(s.length()==1) {
            if(islower(s[0])) {
                s[0]=toupper(s[0]);
            }
           
        }
        for(ll i=0;i<s.length();i++) {
            if(islower(s[i])) {
                anylower=1;
            }
            else {
                alllower=0;
            }
        }
        
        if(alllower==1) {
          cout<<s;
        }
        else {
        if(anylower==0) { 
            for(ll i=0;i<s.length();i++) {
              s[i] = tolower(s[i]);
            }

        }
        else { // there is any lower
            s[0] = toupper(s[0]);
        
        for(ll i=1;i<s.length();i++) {
            if(isupper(s[i])) {
                s[i] = tolower(s[i]);
            }
        } } 
        cout<<s; 
    }
    }
 return 0;
}