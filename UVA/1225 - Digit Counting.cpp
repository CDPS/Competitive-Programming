#include <bits/stdc++.h>

using namespace std;

int m[10001][10];

void calc(){
    memset(m,0,sizeof m);

    for(int i=1;i<=10000;i++){
        int n = i;
        while(n){
            m[i][n%10]++;
            n/=10;
        }
        for(int j=0;j<=9;j++)
            m[i][j]+= m[i-1][j];
    }
}

int main(){

    calc();

    int t,n;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        for(int i=0;i<=9;i++){
            printf("%d%s",m[n][i], i == 9 ? "\n":" ");
        }
    }
    return 0;
}
