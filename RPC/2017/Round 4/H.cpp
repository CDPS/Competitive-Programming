#include <bits/stdc++.h>

using namespace std;


string conver(long long n){
    string s ="";
    while(n){
        int d = n%2;
        s  = (d==1)? s+'1': s+'0';
        n/=2;
    }
    return s;
}

long long num(string s){
    long long res =0;
    for(int i=0; i< s.length()-1;i++){
        if(s[i]=='1')
            res=  res+  ( (1ll << (i+1ll) ) );
    }
    return res;
}

int main(){

    long long n;

    while(cin >> n && n){
            string s = conver(n);
            cout << num(s) + 1ll << "\n";
    }
    return 0;
}
