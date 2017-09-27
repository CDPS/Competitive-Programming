#include <bits/stdc++.h>

using namespace std;


int main(){

    string n,m;
    cin >> n >> m;

    string res ="";
    for(int i=0; i< n.size();i++){
        if(n[i]!=m[i])res+='1';
        else res+='0';
    }

    cout << res << "\n";
    return 0;
}
