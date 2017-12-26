#include <bits/stdc++.h>

using namespace std;


long f(long x){

    long ans =0;
    long factor=1;
    while(x){
        int d = x%10;
        if(d!=0)
            ans = (d*factor)+ans,factor*=10;;
        x/=10;
    }
    return ans;
}

int main(){

    long a,b,c;
    cin >> a >> b;
    c = a+b;
    cout <<( ( f(a) + f(b) == f(c)) ?"YES": "NO" )<< "\n";
    return 0;
}
