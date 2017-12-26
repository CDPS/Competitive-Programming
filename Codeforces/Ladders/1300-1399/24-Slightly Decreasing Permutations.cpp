#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    scanf("%d %d",&n,&k);

    bool first = 1;
    for(int i=0;i<k;i++)
        if(first) printf("%d",n),first=false;
        else printf(" %d",n-i);

    for(int i=1;i<=n-k;i++)
        if(first) printf("%d",i),first=false;
        else printf(" %d",i);
    printf("\n");
    return 0;
}
