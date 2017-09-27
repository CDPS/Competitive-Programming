#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,n;
    scanf("%d %d %d",&a,&b,&n);

    int aux; bool f=0;
    for(int i=0;i<10;i++){
        aux = a*10; aux += i;
        if(aux%b==0){ f=1;break;}
    }
    if(!f){
        printf("-1\n");
        return 0;
    }
    printf("%d",aux);
    for(int i=0;i<n-1;i++)
        printf("0");
    printf("\n");
    return 0;
}
