#include <bits/stdc++.h>

using namespace std;

int   g[1000][1000];o
int out[1000];

int main(){

    int n;
    scanf("%d",&n);

    int u;
    for(int i=1;i<n;i++){
        scanf("%d",&u);
        g[u-1][i]=1;
        out[u-1]++;
    }

    bool f=true;
    for(int i=0;i<n;i++){

        if(out[i]==0) continue;
        if(out[i]>=1 &&out[i]<=2) {f=false;break;}

        int c = 0;
        if(out[i]>=3){
            for(int j=0;j<n;j++)
                if(g[i][j] && out[j]==0)c++;
        }
        if(c<3) {f= false; break;}
    }
    printf("%s\n",(f)?"Yes":"No");
    return 0;
}
