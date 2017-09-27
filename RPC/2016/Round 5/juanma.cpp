#include <bits/stdc++.h>

using namespace std;



int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);
        long long res= (n*n*n*n)-(6*n*n*n)+(23*n*n)-(18*n)+24;
        printf("%lld\n",res/24);
    }

    return 0;
}
