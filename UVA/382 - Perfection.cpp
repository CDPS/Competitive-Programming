#include <bits/stdc++.h>

using namespace std;

int sum(int n){
    int res=0;
    for(int i=1;i<n;i++)
        if(n%i==0)
            res+=i;
    return res;
}
int main(){

    int n;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n) && n){
        int res = sum(n);
        if(res==n)
            printf("%5d  PERFECT\n",n);
        else if(res>n)
            printf("%5d  ABUNDANT\n",n);
        else
            printf("%5d  DEFICIENT\n",n);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
