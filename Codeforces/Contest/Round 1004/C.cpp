#include <bits/stdc++.h>

using namespace std;


int solve(int n){
    for(int k = 0; k <= 7;k++){
        string s = to_string(n-k);
        int mini = 7;
        for(int i = s.size()-1; i>= 0; i--){
            int d = s[i] - '0';
            mini = min(mini, (7-(d%10)+10)%10 );
        }
        if(mini <= k) return k;
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
