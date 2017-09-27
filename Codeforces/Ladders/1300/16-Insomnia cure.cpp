#include <bits/stdc++.h>

using namespace std;


int m[100001];
int f[ 4];

void calc(int n){

    for(int i=0;i<=n;i++)
        m[i]=0;

    for(int i=0;i<4;i++){
        for(int j=f[i];j<=n;j+=f[i]){
            m[j]++;
        }
    }
}
int main(){

    for(int i=0;i<4;i++)
        scanf("%d",f+i);
    int n;
        scanf("%d",&n);

    calc(n);

    int res=0;
    for(int i=0;i<=n;i++)
        if(m[i]) res++;
    printf("%d\n",res);
    return 0;
}
