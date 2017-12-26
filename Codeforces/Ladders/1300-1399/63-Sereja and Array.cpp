#include <bits/stdc++.h>

using namespace std;

long long a[100000];
long long r[100000];
int n,m,acc;

int main(){

    scanf("%d %d",&n,&m);
    acc=0;
    for(int i=0;i<n;i++)
        scanf("%I64d",a+i),r[i]=0;

    int op,idx,val;
    while(m--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d %d",&idx,&val);
            idx--;
            r[idx] =acc;
            a[idx]=val;
        }else if(op==2){
            scanf("%d",&val);
             acc= acc + val;
        }else{
            scanf("%d",&idx);
            idx--;
            printf("%I64d\n",(acc - r[idx])  + a[idx]  );
        }
    }
    return 0;
}
