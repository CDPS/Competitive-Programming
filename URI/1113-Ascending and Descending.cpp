#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m;

    while(scanf("%d %d",&n,&m)){

        if(n==m)
            break;

        if(n<m)
            printf("Crescente\n");
        else if(n>m)
            printf("Decrescente\n");

    }
    return 0;
}
