#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, k, x;
    cin >> t;

    while(t--){

        cin >> n >> k;

        int mini = k -1, ones = 0, twos = 0;
        for(int i=0;i<n;i++){
            cin >> x;
            if(x%k==0) mini = 0;
            if(x%2==0) twos++;
            mini = min(mini, k-(x%k));
        }

        if(k==4){
            if(n-twos >=2) mini = min(2, mini);
            if(n-twos >=1 && twos>=1 ) mini =min(1, mini);
            if(twos >=2 ) mini = 0;
        }
        cout << mini << "\n";
    }
    return 0;
}
