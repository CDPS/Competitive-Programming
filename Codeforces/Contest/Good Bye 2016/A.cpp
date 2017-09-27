#include <bits/stdc++.h>

using namespace std;


int main(){

    int n,k;

    int limit = 60*4;
    scanf("%d %d",&n,&k);

    int i=0;

    while(i<=n){
        k+=(i*5);
        if(k> limit) {i--; break;};
        if(k==limit)
            break;
        if(i==n)
            break;
        i++;
    }
    printf("%d\n",i);
    return 0;
}
