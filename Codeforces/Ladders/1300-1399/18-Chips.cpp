#include <bits/stdc++.h>

using namespace std;


int main(){

    int n,k;
    scanf("%d %d",&n,&k);
    int i=1;
    while(true){

        if(i==n+1) i=1;
        if(k-i<0)break;
        k= k -i;
        i++;
    }

    printf("%d\n",k);
    return 0;
}
