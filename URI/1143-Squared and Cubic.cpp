#include <bits/stdc++.h>

using namespace std;


int pown(int b,int e){

    int t=1;
    for(int i=0;i<e;i++)
        t*=b;
    return t;
}
int main(){
    int n;


    scanf("%d",&n);


    for(int i=1;i<=n;i++){
        printf("%d",i);

        for(int j=2;j<=3;j++){
            printf(" %d",pown(i,j));
        }
        printf("\n");
    }

    return 0;
}
