#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,x,y;

    cin >> n >> x >>y;
    double r = (double(y)/100.0)*(double (n)) - double(x);

    int ans =ceil(r);
    ans = (ans>=0)? ans:0;
    cout <<  ans << "\n";
    return 0;
}
