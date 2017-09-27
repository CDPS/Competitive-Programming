#include <bits/stdc++.h>

using namespace std;

int dp(int n,int idx,string acc ){

    if(idx==n){
        cout << acc << "\n";
        return 1;
    }

    int ans = 0;

    for(int i=1;i<n;i++){
        ans+= dp(n,idx+i,acc+= i+ '0');
    }

    return ans;
}



int main(){
    cout << dp(3,0,"");
    return 0;
}
