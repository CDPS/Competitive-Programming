#include <bits/stdc++.h>

using namespace std;

int n;
int p;
int a[51];

int dp(){
    int maxS=0,maxE=0;
    for(int i=0;i<n;i++){
        maxE= maxE + a[i];
        if(maxE<0){
            maxE=0;
        }
        if(maxS<maxE)
            maxS=maxE;
    }
    return maxS;
}
int main(){

    while(scanf("%d",&n)==1){

        scanf("%d",&p);

        for(int i=0;i<n;i++){
            scanf("%d",a+i);
            a[i]-=p;
        }

        int r = dp();

        printf("%d\n",r);
    }
    return 0;
}
