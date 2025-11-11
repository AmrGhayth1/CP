#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a , b , x , y;
    int t ; 
    cin >> t ;
    while (t --)
    {
cin >> a >> b >> x >> y ; ;
if (a > b && x > y || b > a && y > x  ) { cout << "YES" << endl ; }
else {  cout << "NO" << endl ;}

    }
    
return 0;
}
