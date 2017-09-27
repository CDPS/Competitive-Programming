#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;

    unsigned long long f[65];
    f[0]=0;
    f[1]=1;

    for(int i=2;i<65;i++){
        f[i]= f[i-1]+ f[i-2];
    }

    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);

        printf("Fib(%d) = %llu\n",n,f[n]);

    }
    return 0;
}
