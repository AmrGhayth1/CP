
#include <bits/stdc++.h> 
 using namespace std;
int main() {
    int t ;                        // NOUR ON TOP 
    cin >> t ;
    while (t--){
        int n , m , p , q ;
        cin >> n >> m >> p >> q ;
        int x = n / p ;
        int y = n % p ;
        if ( y == 0 ){
            if ( x * q == m) 
                cout << "YES" << endl ;
                else cout << "NO" << endl ;
        }
         else {
            cout << "YES" << endl ;
        }
        
    }

    return 0;
}