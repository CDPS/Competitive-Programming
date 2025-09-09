#include <bits/stdc++.h>

using namespace std;

int a[200000];
int n;

bool solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    int mini = a[0];
    for(int i=1;i<n;i++){
        if(a[i]-mini>= mini) return false;
        mini=min(mini, a[i]);
    }
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << (solve()? "YES" : "NO" )<< "\n";

    return 0;
}
