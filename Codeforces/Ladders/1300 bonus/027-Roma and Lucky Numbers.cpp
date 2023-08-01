#include <bits/stdc++.h>

using namespace std;

bool isLucky(int n, int k){
    int ans = 0;
    while(n>0){
        int d = n % 10;
        if(d==4 || d==7)
            ans++;
        n/=10;
    }
    return ans <= k;
}

int main(){

    int n, k, x, ans=0;

    cin >> n >> k;

    for(int i=0;i<n;i++){
        cin >> x;
        if(isLucky(x,k))
            ans++;
    }
    cout << ans << "\n";
    return 0;
}
