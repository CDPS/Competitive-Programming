#include <bits/stdc++.h>

using namespace std;


string ans[10] = { "O-|-OOOO",
                   "O-|O-OOO",
                   "O-|OO-OO",
                   "O-|OOO-O",
                   "O-|OOOO-",
                   "-O|-OOOO",
                   "-O|O-OOO",
                   "-O|OO-OO",
                   "-O|OOO-O",
                   "-O|OOOO-"};
int main(){

    string n;

    cin >> n;

    for(int i = n.size()-1;i >=0 ; i--){
        cout << ans[ n[i]-'0' ] << "\n";
    }
    return 0;
}
