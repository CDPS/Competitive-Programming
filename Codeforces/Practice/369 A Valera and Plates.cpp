#include <bits/stdc++.h>

using namespace std;

int t = 1, n, x;
int a[3];

int solve(){

    cin >> n >> a[1] >> a[2];

    int ans = 0;
    for(int i=0;i<n; i++){
        cin >> x;

        if(a[x] > 0 ){
            a[x]--; continue;
        }

        if( a[x-1] > 0){
            a[x-1]--; continue;
        }
        ans++;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << solve() << "\n";

    return 0;
}


