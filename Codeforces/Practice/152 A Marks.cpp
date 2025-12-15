#include <bits/stdc++.h>

using namespace std;

int n, m;
string a[100];

int solve(){

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];

    vector<bool> record(n, false);
    for(int j=0;j<m;j++){
        int maxi = 0;
        for(int i=0;i<n;i++)
            maxi = max(maxi, a[i][j] - '0');

        for(int i=0;i<n;i++)
             record[i] = record[i] | a[i][j]-'0' == maxi;
    }

    int ans = 0;
    for(int i=0;i<n;i++)
        ans+= record[i];

    return ans;

}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
