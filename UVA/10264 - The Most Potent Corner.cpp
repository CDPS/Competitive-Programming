#include <bits/stdc++.h>

using namespace std;

int w[1 << 15];
int s[1 << 15];

int main(){

    int n;
    while(cin >> n){

        int m  = (1 << n);
        for(int i=0;i<m;i++)
            cin >> w[i];

        int acc;
        for(int i=0;i<m;i++){
            acc = 0;
            for(int j=0;j<n;j++)
                acc += w[i^(1<<j)];
            s[i]=acc;
        }

        int ans = -1;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                ans = max( ans, s[i] + s[i^(1<<j)]);

        cout << ans << "\n";
    }
    return 0;
}
