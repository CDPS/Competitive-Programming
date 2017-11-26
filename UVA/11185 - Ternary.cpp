#include <bits/stdc++.h>

using namespace std;

void ternary(long long n){

    string s  = "";
    if(n==0) {cout <<  "0\n";return;}

    while(n){
        int d = n%3;
        s = char(d+'0')+ s;
        n/=3;
    }

    cout << s << "\n";
}

int main(){
    long long n;
    while(cin >> n){if(n<0) break; ternary(n);}
    return 0;
}
