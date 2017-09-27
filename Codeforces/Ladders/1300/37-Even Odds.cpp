#include <bits/stdc++.h>

using namespace std;

int main(){
    long long k,n;

    cin >> n >> k;

    long long m;

    if(n%2==0)
        m=n;
    else
        m= n+1;

    if(k<=(m/2) ){
        k--;
        cout << (2*k) +1 << "\n";
    }else{
        k-=(m/2);
        cout << 2*k<< "\n";
    }

    return 0;
}
