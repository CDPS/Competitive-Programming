#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){
aunque
    cin >> n;
    vector<int> a(n*2 + 1);

    for(int i=0;i<n;i++)
        cin >> x, a[x] = i+1;

    int ans = 0;
    for(int i=1;i<=2*n;i++){
        if(a[i] == 0) continue;
        for(int j = 1; i*j<=2*n; j++)
            if(a[j]!=0 && a[j]!=a[i] && i*j == a[i] + a[j])
                ans++;
    }
    return ans/2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
