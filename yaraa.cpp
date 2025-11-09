#include <bits/stdc++.h>
using namespace std;
int sumallunits(int n) {
    if(n==0) {
        return 0;
    }
    int newn = n%10;

   return newn + sumallunits(n/10);
}
int main() {
   int n;
   cin>>n;
   cout<< sumallunits(n);

return 0;
}