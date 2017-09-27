#include <bits/stdc++.h>

using namespace std;

int main(){

    while(true){
        int n,m;

        scanf("%d %d",&n,&m);

        if(n<=0 || m<=0)
            break;
        if(n>m)
            swap(n,m);
        int sum=0;
        for(int i=n;i<=m;i++){
            printf("%d ",i);
            sum+=i;
        }
        printf("Sum=%d\n",sum);

    }
    return 0;
}
