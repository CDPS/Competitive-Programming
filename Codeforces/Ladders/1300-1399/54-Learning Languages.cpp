#include <bits/stdc++.h>

using namespace std;

int n,m,g[100][100],visit[100];
int acc[100];

void dfs(int x){
    for(int i =0;i<m;i++){
        if(g[x][i]){
            for(int j=0;j<n;j++){
                if(j!=x && g[j][i] && !visit[j]){
                    visit[j]=1;
                    dfs(j);
                }
            }
        }
    }
}

int main(){

    scanf("%d %d",&n,&m);

    int k,l;

    for(int i=0;i<n;i++){
        visit[i]=0;
        scanf("%d",&k);
        acc[i]=k;
        for(int j=0;j<k;j++){
            scanf("%d",&l);
            g[i][l-1]=1;
        }
    }

    l=n;
    int ans = 0;
    int empties =0;
    for(int i=0;i<l;i++){

        if(acc[i]==0){
            empties++;
            visit[i]=1;
        }
        else if(!visit[i]){
            visit[i]=1;
            dfs(i);
            ans++;
        }
    }
    if(ans==0) ans=1;
    printf("%d\n",ans-1+ empties);
    return 0;
}
