#include <bits/stdc++.h>

using namespace std;

int t, n, k, x;

int solve(){

    cin >> n >> k;

    vector<int> a(n + 1, 0);
    for(int i=0;i<n;i++)
        cin >> x , a[x]++;

    int ans = 0;
    for(int i=0;i<k;i++){
        if(a[i]==0) {
            ans++;
            if(a[k]> 0)
                a[k]--;
        }
    }

    return ans + a[k];
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
