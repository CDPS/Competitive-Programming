#include <bits/stdc++.h>

using namespace std;

int n, s;

bool a[2000000];

int solve(){

    cin >> n >> s;

    for(int i=0;i<n;i++) cin >> a[i];

    int ans =  n+ 1, acc = 0;
    for(int i=0, j=0;j<n;j++){
        acc+=a[j];
        while(i < n && acc > s) acc-=a[i++];
        if(acc==s)
            ans = min(ans, n-(j-i+1));
    }
    return ans==n+1? -1 : ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
