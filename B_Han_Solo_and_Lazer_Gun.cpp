#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long q;
    string action;
    int n;
    deque <int> dq;
    bool reverse = false;
    cin>>q;
    for(long long i=0;i<q;i++) {
        cin>>action;
        if(action=="reverse") {
            reverse =! reverse; } 
            
            else if(action=="push_back") {
                 if(reverse) {
             cin>>n;
             dq.push_front(n);
         }
         else {  cin>>n;         
                 dq.push_back(n); } }
                 
             
         else if(action=="toFront") {
              if(reverse) {
             cin>>n;
             dq.push_back(n); }
             else {cin>>n;
             dq.push_front(n); }}
             
             
         
        else if(action=="front") {
             if(reverse) {
             if(dq.empty()) {cout<<"No job for Ada?"<<endl;}
             else {cout<<dq.back()<<endl;
             dq.pop_back();} }
             else {if(dq.empty()) {cout<<"No job for Ada?"<<endl;}
             else {cout<<dq.front()<<endl;
             dq.pop_front();}} }
             
             
         
        else if(action=="back") {
             if(reverse) {
             if(dq.empty()) {cout<<"No job for Ada?"<<endl;}
             else {cout<<dq.front()<<endl;
             dq.pop_front();} }
             else {if(dq.empty()) {cout<<"No job for Ada?"<<endl;}
             else {cout<<dq.back()<<endl;
             dq.pop_back();}} 
         }
            
    }
 
   return 0;
}
