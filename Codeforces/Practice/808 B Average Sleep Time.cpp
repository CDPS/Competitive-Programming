#include <bits/stdc++.h>

using namespace std;

int n,k;
long long acc[200001];

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios_base::fixed);
    cout.precision(10);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> acc[i+1], acc[i+1]+=acc[i];

    double ans = 0, div =0;
    for(int i=k;i<=n;i++)
        ans +=  acc[i] - acc[i-k], div++;

    cout << ans/div << "\n";

    return 0;
}
