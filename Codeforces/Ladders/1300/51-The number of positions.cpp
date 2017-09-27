#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);

    int res=0;
    for(int i=0;i<=b;i++){
        int r= n-i;
        if((r-1)>=a)
            res++;
    }

    printf("%d\n",res);
    return 0;
}
