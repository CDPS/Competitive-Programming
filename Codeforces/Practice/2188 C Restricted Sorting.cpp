#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200000];
int b[200000];

bool sorted(){
    for(int i=1;i<n;i++)
        if(a[i] < a[i-1])
            return false;
    return true;
}
int solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i], b[i] = a[i];


    if(sorted())
        return -1;

    sort(b , b + n);

    int maxi = b[n-1];
    int mini = b[0];

    int ans = 1e9;
    for(int i=0;i<n;i++){
        if(a[i] == b[i]) continue;
        int dist_mini = a[i] - mini;
        int dist_maxi = maxi - a[i];
        ans = min(ans, max(dist_maxi, dist_mini));
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
