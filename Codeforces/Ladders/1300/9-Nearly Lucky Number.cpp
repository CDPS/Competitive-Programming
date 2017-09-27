#include <bits/stdc++.h>

using namespace std;

bool isLucky(string n){

   int res=0;
   for(int i=0;i<n.size();i++){
        if(n[i]-'0'==4) {res++; continue;}
        if(n[i]-'0'==7) {res++; continue;}
   }

    stringstream ss;
    ss << res;
    string s;
    ss >> s;

    for(int i=0;i<s.size();i++){
        if(s[i]-'0'==4) continue;
        if(s[i]-'0'==7) continue;
        return false;
   }
   return true;
}
int main(){
    string  n;
    cin >> n;

    if(isLucky(n) )cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
