#include <bits/stdc++.h>

using namespace std;

int m=11;

int div(string n){
    int p=1,ans=0;
    for(int i=n.size()-1;i>=0;i--){
        ans = ((ans%m) + (((n[i]-'0')*p)%m) )%m;
        p = ( (10) * (p%m) )%m;
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    string n;
    while(cin >> n && n!="0"){
        if(div(n)==0) cout << n << " is a multiple of 11.\n";
        else cout << n << " is not a multiple of 11.\n";
    }
    return 0;
}
