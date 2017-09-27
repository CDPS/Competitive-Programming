#include <bits/stdc++.h>

using namespace std;


int main(){

    long n,b;
    while(cin >> n >> b){
        if(n==0 && b==0)
            break;
        long acc =0,aux;

        for(int i=0;i<n;i++){
            cin >> aux; acc+=aux;
        }
        long ans = b/acc;
        cout << ans << "\n";
    }
    return 0;
}
