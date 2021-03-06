#include <bits/stdc++.h>
 
using namespace std;
 
long long memo[11][2][2][11];
 
long long dp(string &n,int idx,int top, int first,int acc){
 
    if(idx==n.size()){
        return acc;
    }
 
    if(memo[idx][top][first][acc]!=-1){
        return memo[idx][top][first][acc];
    }
 
    int mmax = (top)? n[idx] - '0' : 9;
 
    long long ans=0;
    for(int i=0;i<=mmax;i++){
      int nacc = acc;
      if(first && i==0){
          nacc++;
      }
 
      ans+=  dp(n,idx+1, top&&(i==mmax),i!=0 || first, nacc);
    }
 
    return memo[idx][top][first][acc]=ans;
 
}
 
int main() {
 
  int  t,caseno=1;
  scanf("%d",&t);
 
 
  while(t--){
 
      long an;
      string a,b;
      cin >> an >> b;
 
      long long res=0;
      if(an==0){
        an++;
        res++;
      }
 
 
      stringstream strstream;
      strstream << --an;
      strstream >> a;
 
      memset(memo,-1,sizeof memo);
      long long res1= dp(b,0,1,0,0);
 
 
      memset(memo,-1,sizeof memo);
      long long res2= dp(a,0,1,0,0);
 
      res+= res1 - res2;
      printf("Case %d: %lld\n",caseno++,res);
  }
  return 0;
}

