#include <bits/stdc++.h>

using namespace std;

int main(){

    int a [3];
    int b[3];
    for(int i=0;i<3;i++){
        scanf("%d",i+a);
        b[i]=a[i];
    }

    sort(a, a+3);
    for(int i=0;i<3;i++){
        printf("%d\n",a[i]);
    }

    printf("\n");

    for(int i=0;i<3;i++){
        printf("%d\n",b[i]);
    }

    return 0;
}
