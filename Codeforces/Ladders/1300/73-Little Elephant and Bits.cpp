#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    int j;
    for(int i=s.size();i>=0;i--) if(s[i]=='1'){ j=i;break;}


    bool f=0;
    for(int i=j;i>=0;i--) if(s[i]=='0'){ j=i; f=1; }

    if(!f) j = s.size()-1;

    for(int i=0;i<s.size();i++)
        if(i!=j) cout << s[i];
    cout << "\n";
    return 0;
}
