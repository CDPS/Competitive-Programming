#include <bits/stdc++.h>

using namespace std;

int killed [1025][1025];

int t,d, n,x,y,w;

void update(int x,int y,int k){
    for(int i= x-d;i<=x+d;i++)
        if(i>0 && i < 1025)
         for(int j=y-d;j<=y+d;j++)
             if(j>0 && j < 1025)
                killed[i][j]+=k;
}

int main(){

    scanf("%d",&t);

    while(t--){
        scanf("%d",&d);
        scanf("%d",&n);

        for(int i=0;i<1025;i++)
            for(int j=0;j<1025;j++)
                killed[i][j]=0;

        for(int i=0;i<n;i++){
            scanf("%d %d %d",&x,&y,&w);
            update(x,y,w);
        }

        int aux=-1;
        for(int i=0;i<1025;i++){
            for(int j=0;j<1025;j++){
                if(aux < killed[i][j]){
                    aux=killed[i][j];
                    x=i; y = j;
                }
            }
        }
        printf("%d %d %d\n",x,y,aux);
    }
    return 0;
}
