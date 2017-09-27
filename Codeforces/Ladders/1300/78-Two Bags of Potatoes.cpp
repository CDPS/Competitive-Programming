#include <bits/stdc++.h>

using namespace std;

int main(){

    long long y,k,n;

    cin >> y >> k >> n;

    bool f=0;
    long long m=k;

    if(y>n){
        cout <<"-1";
        return 0;
    }
    while(k<=y){
        k+=m;
    }

    if(k>n){
        cout <<"-1";
        return 0;
    }


    long long start = k-y;

    while(start + y <= n){
        cout << start << " ";
        start+=m;
    }

    return 0;
}
