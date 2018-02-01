#include <bits/stdc++.h>

using namespace std;

string a,b;

int memo[1000][1000],n,m;

int dp(int idx,int idy){

    if(idx == n || idy == m) return 0;

    if(memo[idx][idy]!=-1)  return memo[idx][idy];

    return memo[idx][idy]= (a[idx]==b[idy])? 1 + dp(idx+1,idy+1) : max(  dp(idx+1,idy) , dp(idx,idy+1) );
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(getline(cin,a)){
        getline(cin,b);
        n = a.size(); m = b.size();
        memset(memo,-1,sizeof memo);
        cout << dp(0,0) << "\n";
    }
    return 0;
}
