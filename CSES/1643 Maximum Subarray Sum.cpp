#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    long long n, x, sum = 0, ans= -1e10, mini = 0;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        sum += x;
        ans  = max(ans,sum - mini);
        mini = min(mini, sum);
    }

    cout << ans << "\n";

    return 0;
}

