#include <bits/stdc++.h>

using namespace std;

int t , n;
int a[3105];

int solve(){

    cin >> n;

    for(int i=0; i<n; i++) cin >>a[i];

    int ans = -1;
    for(int i=0; i<n; i++)
         for(int j=i + 1; j<n; j++)
            ans = max(ans, a[i]^a[j]);

    return ans;
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
