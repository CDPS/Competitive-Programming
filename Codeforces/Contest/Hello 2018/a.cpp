#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n,m,idx=0;

    cin >> n >> m;

    long long factor=1;
    while(factor<=m && idx <n){
        factor = factor*2;
        idx++;
    }
    cout << m%factor << "\n";
    return 0;
}
