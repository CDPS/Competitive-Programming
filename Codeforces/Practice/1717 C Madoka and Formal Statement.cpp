#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200000], b[200000];

bool solve(){

    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=0;i<n;i++){
        if(a[i] > b[i])
            return false;
        if(a[i] < b[i] && b[i] > b[ (i+1)%n]  + 1)
            return false;
    }

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO" ) << "\n";

    return 0;
}
