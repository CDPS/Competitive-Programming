#include <bits/stdc++.h>

using namespace std;

int n, t, x;

int solve(){

    cin >> n;
    vector<int> v(n);

    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> x , v[i]= x - v[i];

    sort(v.begin(), v.end());

    int ans =0, i = 0, j = n-1;
    while(i<j){
        if(v[i] + v[j] < 0  ) i++;
        else
            i++,j--, ans++;
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
