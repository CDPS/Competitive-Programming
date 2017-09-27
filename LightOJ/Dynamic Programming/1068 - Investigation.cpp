#include <bits/stdc++.h>
 
using namespace std;
 
int dp[10][3][100][100];
 
int k;
 
int f(string n,int idx,int top,int acc,int num){
 
    if(idx==n.size()){
 
        return (acc%k==0) && (num==0);
    }
 
    if(dp[idx][top][acc][num]!=-1)
        return dp[idx][top][acc][num];
 
    int max= (top? (n[idx]-'0'):9);
 
    int res=0;
 
    for(int i=0;i<=max;i++){
        res+= f(n,idx+1,top&&(i==max), acc+i, ( ((num*10)%k) +i)%k);
    }
 
    return dp[idx][top][acc][num]=res;
}
 
int main(){
 
    int t,caseno=1;
 
    scanf("%d",&t);
 
    while(t--){
        int an;
        string a,b;
 
        cin >> an >> b >> k;
 
        if(k>99){
            printf("Case %d: 0\n",caseno++);
            continue;
        }
 
        stringstream strstream;
        strstream << --an;
        strstream >> a;
 
 
        memset(dp,-1,sizeof dp);
        int res2 = f(b,0,1,0,0);
 
        memset(dp,-1,sizeof dp);
        int res1 = f(a,0,1,0,0);
 
        int res= res2-res1;
 
        printf("Case %d: %d\n",caseno++,res);
    }
 
    return 0;
}
