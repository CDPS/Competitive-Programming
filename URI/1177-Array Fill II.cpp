#include <bits/stdc++.h>

using namespace std;

int main(){

    int a[1000];
    int n;
    scanf("%d",&n);

    for(int i=0;i<1000;i++){
        a[i]=i%n;
    }

    for(int i=0;i<1000;i++){
        printf("N[%d] = %d\n",i,a[i]);
    }
    return 0;
}
