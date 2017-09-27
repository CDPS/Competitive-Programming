#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string s,t;
    cin.ignore();
    while(n--){
        getline(cin,s);

        t="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                    t+= s[i],t+= 'p',t+=s[i];
            else
                t+=s[i];
        }

        cout << t << "\n";
    }
    return 0;
}
