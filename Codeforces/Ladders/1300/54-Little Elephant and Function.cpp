#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    if(n==1){
        printf("1\n"); return 0;
    }

    printf("%d",n);
    for(int i=1;i<=n-1;i++)
        printf(" %d",i);
    printf("\n");
    return 0;
}
