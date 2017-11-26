#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    int t;
    string op;
    int k;
    long long res =0;
    cin >> t;

    while(t--){
        cin >> op;
        if(op[0]=='d'){
            cin >>k;
            res = res + k;
        }else{
            cout << res << "\n";
        }
    }
    return 0;
}
