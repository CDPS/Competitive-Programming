#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=2;i<=n;i+=2){
        printf("%d^2 = %ld\n",i , i*i);
    }
    return 0;
}
