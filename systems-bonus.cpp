#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define endl "\n"
#define AMR  ios::sync_with_stdio(0); cin.tie(0);using namespace std;

struct test {
    int a;
    char b;
    float c;
    double d;
};

void DetEndian() {
    uint32_t x = 0x01020304;
    char* c = (char*)&x;
    if (*c == 0x04) {
        cout << "System is Little-Endian "<< endl ;
    } else {
        cout << "System is Big-Endian" << endl ;
    }
}

void str() {
    cout << endl ; 
    cout << "Analyzing struct " << endl ;
    cout << "struct test {" << endl ;
    cout << " int a;   // Offset " << offsetof(test, a) << endl ;
    cout << " char b;  // Offset " << offsetof(test, b) << endl ;
    cout << " float c; // Offset " << offsetof(test, c) << endl ;
    cout << " double d;// Offset " << offsetof(test, d) << endl ;
    cout << "};" << endl ;

    size_t tt = sizeof(test);
    cout << "Total struct size " << tt << " bytes" << endl ;

    size_t pad1 = offsetof(test, b) - (offsetof(test, a) + sizeof(((test*)0)->a));
    size_t pad2 = offsetof(test, c) - (offsetof(test, b) + sizeof(((test*)0)->b));
    size_t pad3 = offsetof(test, d) - (offsetof(test, c) + sizeof(((test*)0)->c));
    size_t pad4 = tt - (offsetof(test, d) + sizeof(((test*)0)->d));

    size_t tp = pad1 + pad2 + pad3 + pad4;

    if (tp > 0) {
        cout << "Padding detected " << tp << " bytes" << endl ;
        if (pad1) cout << " - " << pad1 << " byte(s) after 'a'" << endl ;
        if (pad2) cout << " - " << pad2 << " byte(s) after 'b'" << endl ;
        if (pad3) cout << " - " << pad3 << " byte(s) after 'c'" << endl ;
        if (pad4) cout << " - " << pad4 << " byte(s) at the end" << endl ;
    } else {
        cout << "No padding detected " << endl ;
    }
}

int main() {
    AMR
    DetEndian();
    str();
    return 0;
}
