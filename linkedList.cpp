#include <iostream>
using namespace std;
int main() {
    int a[5];
    int min= 1e5 ; 
    int sum=0;
    for (int i=0;i<5;i++){
        cin>>a[i];
        if((min>(a[i]%10)) && (a[i]%10)){
            min=a[i] % 10;
        }
       if (a[i]%10){
       a[i] += 10 - (a[i] % 10);
       }
       sum+=a[i];
    }
    //if(min ){
      //cout<<sum-(10-min) ;
    //}
    //else{
        cout<< sum  ;
    //}
    return 0;
}
