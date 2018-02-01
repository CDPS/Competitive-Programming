#include <bits/stdc++.h>

using namespace std;

int memo[10][2][2];
string s;

int dp(int idx, int top,int ant){

  if(idx == s.size()) return   0;
  if(memo[idx][top][ant]!=-1) return memo[idx][top][ant];

  int maxi = top? s[idx]-'0' : 1 ;

  int ans = 0;
  for(int i=0;i<=maxi;i++){
     ans = ans + (  (ant==1 && i==1)? 1 : 0  ) + dp(idx+1,top&&(i==maxi),i);
  }

  return memo[idx][top][ant] = ans;
}

string toBinary(int n){
    string s="";
    while(n){ s = ((n%2)%2)? '1'+s :'0'+s; n/=2; }
    return s;
}

int main(){

    int t,n;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        s = toBinary(n);
        memset(memo,-1,sizeof memo);
        cout << dp(1,0,0) + dp(1,1,1) << "\n";
    }
    return  0;
}
