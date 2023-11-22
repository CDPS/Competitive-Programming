#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(NULL); cin.sync_with_stdio(false);

    int t, caseno =1;
    string s;
    cin >> t;

    while(t--){
        cin >> s;
        bitset<50> check;

        for(int i=0;i<s.size();i++){
            if(s[i]=='D'){
                check[i] = 1;
            }
            if(s[i]=='S'){
                check[i]= 1;
                if(i+1<s.size()) check[i+1]=1;
                if(i-1>=0)check[i-1]=1;
            }
            if(s[i]=='B'){
                check[i]= 1;
                if(i-1>=0) check[i-1]=1;
                if(i-2>=0) check[i-2]=1;
            }
        }

        int ans =0;
        for(int i=0;i<s.size();i++)
            if(!check[i]) ans++;

        cout <<"Case " << caseno++ << ": " << ans << "\n";
    }

    return 0;
}
