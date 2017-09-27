#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    while(true){
        scanf("%d",&n);
        if(n==0)
            break;

        printf("1");
        for(int i=2;i<=n;i++)
            printf(" %d",i);
        printf("\n");

    }
    return 0;
}
