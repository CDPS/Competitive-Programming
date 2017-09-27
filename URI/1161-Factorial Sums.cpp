#include <bits/stdc++.h>

using namespace std;


int main(){

    long long f[21];
    f[0]=1;
    f[1]=1;
    for(int i=2;i<22;i++){

        f[i]=i*f[i-1];
    }


    int n,m;
    while(scanf("%d %d",&n,&m)==2){
        long long res = f[n]+f[m];
        printf("%lld\n",res);
    }
    return 0;
}
