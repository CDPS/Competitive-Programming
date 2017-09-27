#include <bits/stdc++.h>

using namespace std;

long  a[41];
int main(){

    a[1]=1;
    a[2]=2;
    for(int i=3;i<41;i++){
        a[i]= a[i-2] + a[i-1];
    }

    int n;
    scanf("%d",&n);
    while(n!=0){

        printf("%d\n",a[n]);

        scanf("%d",&n);
    }

    return 0;
}
