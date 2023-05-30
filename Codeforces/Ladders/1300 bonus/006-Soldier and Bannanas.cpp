#include <bits/stdc++.h>

using namespace std;

int main(){

    long n, k, w, res = 0;

    cin >> k >> n >> w;

    res = (w*(w+1))/2;
    res*= k;

    res -=n;

    cout << ((res< 0)? 0 : res )<< "\n";
    return 0;
}
