#include <bits/stdc++.h>
 
using namespace std;
 
int table[10001], coin[100];
int mod=100000007;

int main(){
 
    int t,caseno=1;
    scanf("%d",&t);
  
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
 
        for(int i=0;i<n;i++)
            scanf("%d",coin + i);
 
        memset(table,0,sizeof (table));
 
        table[0] = 1;
        for(int i=0; i<n; i++)
            for(int j=coin[i]; j<=k; j++)
                table[j]= table[j]%mod +(table[j-coin[i]])%mod;

        printf("Case %d: %d\n",caseno++,table[k]%mod);
    }
}

