#include <bits/stdc++.h>
using namespace std;
int spell(int a[], int siz) {
    int n=0;
   int result = a[siz-1]+spell(a,siz-2);
   string str = to_string(result);
    if(str.size()!=1) {
        spell(result, str.size() );
        n++;
    }
    return n;
}
int main() {
    int siz;
    int a[siz];
    for(int i=0;i<siz;i++) {
    cin>>a[i]; }
    cout<<spell(a,siz);
    

 return 0;
}
