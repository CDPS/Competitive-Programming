#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;

    cin >> t;
    while(t--){

        cin >> n;

        if(n%2 == 0){
            cout << -1 << "\n";
            continue;
        }

        cout << 1;
        for(int i = n; i >=2;i--)
            cout << " " << i;
        cout << "\n";

    }
    return 0;
}
