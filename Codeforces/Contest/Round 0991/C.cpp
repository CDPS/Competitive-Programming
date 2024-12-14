#include <bits/stdc++.h>

using namespace std;

bool solve(string s){

    int sum = 0, sum2 =0, sum3=0;
    for(int i=0;i<s.size();i++){
        sum+=s[i]-'0';
        if(s[i]=='2') sum2++;
        if(s[i]=='3') sum3++;
    }

    for(int i=0;i<=min(sum2,8);i++)
        for(int j=0;j<=min(sum3,8);j++)
            if( ( sum + (i*2) + (j*6) )% 9 ==0  )
                return true;

    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t; string s;
    cin >> t;

    while(t--){
        cin >> s;
        cout << ( solve(s)? "YES" : "NO" ) << "\n";
    }
    return 0;
}
