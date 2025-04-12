#include <bits/stdc++.h>

using namespace std;

const long long m = 1e9 + 7;

int main(){

    string s;
    cin >> s;


    string sub = "";

    for(int i=0;i<s.size();i++)
        if(s[i] == 'a' || s[i] == 'b')
            sub+= s[i];

    long long ans = 1;
    for(int i=0;i<sub.size();i++){
        if(sub[i]=='a'){
            long long acc = 0;
            while( i < sub.size() && sub[i] == 'a')
                acc++, i++;

            ans= ((ans%m) * ((acc+1)%m))%m;
        }
    }

    cout << ans - 1 << "\n";
    return 0;
}
