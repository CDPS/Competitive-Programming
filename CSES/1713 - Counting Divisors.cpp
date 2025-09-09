#include <bits/stdc++.h>

using namespace std;

int solve(){

    int n, ans = 0;

    cin >> n;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans++;
            if(n/i!=i) ans++;
        }
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << "\n";
    return 0;
}
