#include <bits/stdc++.h>

using namespace std;

char d = '.';

int main(){

    string s;
    int n,m;
    cin >> n >> m >> s;

    s = "a" + s + "a";

    int groups = 0, dots = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == d ){
            dots++;
            if(s[i-1]!=d) groups++;
        }
    }

    int i;
    char c;
    while(m--){
        cin >> i >> c;
        if(c == d && s[i]!=d)
            dots++;
        if(c!=d && s[i]==d)
            dots--;
        if(s[i-1]==d &&  s[i+1]==d && c == d && s[i]!=d)
            groups--;
        if(s[i-1]==d && s[i+1]==d && c != d && s[i]==d)
            groups++;
        if(s[i-1]!=d && s[i+1]!=d && c != d && s[i]==d)
            groups--;
        if(s[i-1]!=d && s[i+1]!=d && c == d && s[i]!=d)
            groups++;
        s[i] = c;
        cout << dots - groups << "\n";
    }
    return 0;
}
