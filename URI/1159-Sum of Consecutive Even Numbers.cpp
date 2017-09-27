#include <bits/stdc++.h>

using namespace std;

int main(){


    int n=1;
    while(true){
        scanf("%d",&n);

        if(n==0)
            break;

        int res=0;
        if(n%2)
            n++;
        for(int i=n;i<=n+8;i+=2){
            res+=i;
        }
        printf("%d\n",res);
    }
    return 0;
}
