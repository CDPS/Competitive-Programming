#include <bits/stdc++.h>

using namespace std;

int main(){

    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;

    int f = a + b + c + d + e;
    cout << ( (f%5 == 0 && f!=0)? f/5 : -1 )<< "\n";
    return 0
}
