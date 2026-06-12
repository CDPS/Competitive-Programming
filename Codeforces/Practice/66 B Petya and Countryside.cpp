#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[1000];

int solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    int ans = 0 ;
    for(int i=0;i<n;i++){
        int curr = 1;
        for (int j = i - 1; j >= 0 && a[j] <= a[j+1]; j--)
            curr++;
        for (int j = i + 1; j < n  && a[j] <= a[j-1]; j++)
            curr++;
        ans= max(curr, ans);
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    t = 1;
    while(t--)
        cout << solve() << "\n";

    return 0;
}


