#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t,n;
    cin >> t;

    while(t--){

        cin >> n;

        int ans =0;
        for(int i=1;i<=99;i++)
            for(int j=1;j<=99;j++)
                if(i+j == n) ans++;

        cout << ans << "\n";
    }
    return 0;
}
