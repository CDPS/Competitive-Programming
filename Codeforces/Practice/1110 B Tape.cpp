#include <bits/stdc++.h>

using namespace std;

const int oo = 2e9;

int a[100001];

int main(){

    int n, m, k;
    cin >> n >> m >> k;

    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> v;
    for(int i=1;i<n;i++)
        v.push_back(a[i]-a[i-1]+1);

    sort(v.begin(),v.end(),greater<int>());

    int ans = a[n-1] - a[0] + 1;
    for(int i=0;i<k-1;i++)
        ans-= v[i]-1;

    cout << ans + k- 1 << "\n";

    return 0;
}
