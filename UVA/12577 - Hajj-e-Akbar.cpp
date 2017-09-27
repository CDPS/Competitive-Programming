#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;int caseno=1;
    while(cin >> s && s!="*"){
        if(s=="Hajj")
            cout << "Case " << caseno++ << ": Hajj-e-Akbar\n";
        else
            cout << "Case " << caseno++ << ": Hajj-e-Asghar\n";
    }
    return 0;
}
