#include <bits/stdc++.h>

using namespace std;

int m[5][5];

int main(){

    int x,y;

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            scanf("%d",&m[i][j]);
            if(m[i][j]==1){x=i;y=j;}
        }

    int xm=2;
    int ym=2;
    if(x>xm)swap(xm,x);
    if(y>ym)swap(ym,y);

    printf("%d\n", (xm-x)+ (ym-y));
    return 0;
}
