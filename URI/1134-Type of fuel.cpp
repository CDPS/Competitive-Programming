#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    int a[3]={0,0,0};

    while(true){

        scanf("%d",&n);

        if(n==4)
            break;

        if(n>=1 && n<=3)
            a[n-1]++;
    }

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n",a[0]);
    printf("Gasolina: %d\n",a[1]);
    printf("Diesel: %d\n",a[2]);

    return 0;
}
