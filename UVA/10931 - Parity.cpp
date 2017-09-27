#include <bits/stdc++.h>

using namespace std;

void getParity(long n){
    int b=0;
    string s="";
    while(n){
        int d = n%2;
        b+=d;
        s= char(d+'0') + s;
        n/=2;
    }
    cout << "The parity of " << s << " is " << b << " (mod 2).\n";
}
int main(){
    long n;
    while(cin >> n && n)
        getParity(n);
    return 0;
}
