#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    while(cin >> n && n){
        int a = 0, b =0;
        bool flag = true;
        for(int i=0;i<32;i++){
            if((n&(1<<i))){
                if(!flag) b|=(n&(1<<i)), flag = true;
                else a|=(n&(1<<i)), flag = false;
            }
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}
