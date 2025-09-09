#include <bits/stdc++.h>

using namespace std;

int t;
string a[1000];

int solve(){

    int n, m;
    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> a[i];

    int layers = min(n, m)/2;

    int ans = 0;
    for(int l=0; l<layers;l++){
        string curr = "";
        for(int i=l;i<m-l;i++) curr += a[l][i];
        for(int i = l+1; i< n-l; i++) curr += a[i][m-l-1];
        for(int i=m-l-2; i>=l; i--)   curr += a[n-l-1][i];
        for(int i=n-l-2; i>=l+1; i--) curr+= a[i][l];

        int k = curr.size();
        for(int i=0;i<k;i++)
            ans += (curr[(i - 3 + k) % k] == '1'
                 && curr[(i - 2 + k) % k] == '5'
                 && curr[(i - 1 + k) % k] == '4'
                 && curr[i] == '3');
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
