#include <bits/stdc++.h>

using namespace std;

string s;

bool solve(){

    bool check = true;
    for(int i=0; i<8; i++){
        cin >> s;
        check &= (s == "WBWBWBWB" || s == "BWBWBWBW");
    }

    return check;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << (solve()? "YES" : "NO" ) << "\n";

    return 0;
}
