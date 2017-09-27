#include <bits/stdc++.h>

using namespace std;

int a[2000], memo[2000][2000];
int n;

int dp(int idx,int first,int last,int idxp){

    if(idx ==n)
        return 0;

    if(memo[idx][idxp]!=-1) return memo[idx][idxp];

    if(a[idx]< a[first] || a[idx]> a[last])
        return dp(idx+1,first,last,idxp);

    if(a[idx]> a[first])
        return memo[idx][idxp] = max( dp(idx+1,first,last,idxp), dp(idx+1,idx,last,idx) +1);

    return memo[idx][idxp] =    max( dp(idx+1,first,last,idxp),dp(idx+1,first,idx,idx) +1);
}

void rmemo(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
                memo[i][j]=-1;
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d",&n);
        if(n ==0 ) {printf("0\n"); continue;}

        for(int i=0;i<n;i++)
            scanf("%d",a+i);

        rmemo();int maxi=1;
        for(int i=0;i<n-1;i++)
            maxi = max(dp(i+1,i,i,i)+1,maxi);
        printf("%d\n",maxi);
    }
    return 0;
}
