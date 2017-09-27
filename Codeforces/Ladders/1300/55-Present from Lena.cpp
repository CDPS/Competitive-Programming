#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector< vector<int> > g (n*2 +1, vector< int> (n*2+1 ,-1) );

    int c;

    for(int i=0;i<=n;i++){
        c =0;
        for(int j=0;j<=n;j++){
            if(j>=n-i){
                g[i][j]=c;
                c++;
            }
        }
    }

    for(int i=0;i<=n;i++){
        c=i;
        for(int j=n;j<=2*n;j++){
            if( (n-j) <=i){
                g[i][j]=c;
                c--;
            }
        }
    }

    for(int i=n;i<=2*n;i++){
        c=0;
        for(int j=0;j<=n;j++){
            if(j>= i-n){
                g[i][j]=c;
                c++;
            }
        }
    }

    for(int i=n;i<=2*n;i++){
        c = n - (i-n);
        for(int j=n;j<=2*n;j++){
            if( j <= 2*n-(i-n) ){
                g[i][j]=c;
                c--;
            }
        }
    }

    bool f=0;

    for(int  i=0;i<=2*n;i++){
        f=0;
        for(int j=0;j<=2*n;j++){

            if(g[i][j]==-1 && f)break;
            else if(g[i][j]!=-1 && !f){
                printf("%d",g[i][j]);
                f=1;
            }
            else if(g[i][j]!=-1){
                printf(" %d",g[i][j]);

            }else{
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}
