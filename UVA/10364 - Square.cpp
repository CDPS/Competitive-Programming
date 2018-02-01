#include <bits/stdc++.h>

using namespace std;

int n,s,memo[(1<<20)][4],a[20];

int dp(int mask,int sides,int acc){

  if( mask == (1<<n)-1 &&sides == 4 ) return 1;

  if(acc == s) return dp(mask, sides +1 , 0);

  if(memo[mask][sides]!=-1) return memo[mask][sides];

  int ans =0;
  for(int i=0;i<n && !ans ;i++)
      if( (mask&(1 << i)) == 0 && acc + a[i] <= s)
          ans = dp(mask | (1<<i),sides,acc + a[i]);
  return memo[mask][sides] = ans;
}

int main(){

    int t;
    scanf("%d",&t);

    while(t--){

      scanf("%d",&n);

      s = 0;
      for(int i=0;i<n;i++) scanf("%d",a+i), s = s + a[i];

      if(s%4==0){
            s/=4;
            memset(memo,-1,sizeof memo);
            int ans = dp(0,0,0);
            printf("%s\n",(ans)? "yes":"no");
      }else{
          printf("no\n");
      }
    }
    return 0;
}
