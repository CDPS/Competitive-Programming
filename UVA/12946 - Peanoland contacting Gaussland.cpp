#include <bits/stdc++.h>

using namespace std;

int t[32][2];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    t[0][0] =  1;  t[0][1] = 0;
    t[1][0] = -1;  t[1][1] = 1;

    for(int i=2;i<32;i++){
        t[i][0] = -t[i-1][0] - t[i-1][1];
        t[i][1] =  t[i-1][0] - t[i-1][1];
    }

    int n;
    while(cin >> n){
        int ans1=0, ans2 =0;
        for(int i=0;i<32;i++){
            if( ( n & ( 1 << i ) ) != 0 )
                ans1 += t[i][0], ans2 += t[i][1];
        }
        cout << ans1 << " " << ans2 << "\n";
    }

    return 0;
}
