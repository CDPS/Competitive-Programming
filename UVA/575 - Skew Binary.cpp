#include <bits/stdc++.h>

using namespace std;

long getNum(string s){
    int e=1;
    long res=0;
    for(int i=s.size()-1;i>=0;i--){
        res+= (s[i]-'0')*((1l<<e) -1 );
        e++;
    }
    return res;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s && s!="0")
        cout << getNum(s) << "\n";
    return 0;
}
