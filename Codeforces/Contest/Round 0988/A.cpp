#include <bits/stdc++.h>

using namespace std;

int a[21];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t, n,x;
    cin >> t;

    while(t--){

        memset(a,0, sizeof a);
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> x , a[x]++;

        int ans =0;
        for(int i=1;i<=20;i++)
            ans += a[i]/2;

        cout << ans << "\n";
    }
    return 0;
}
