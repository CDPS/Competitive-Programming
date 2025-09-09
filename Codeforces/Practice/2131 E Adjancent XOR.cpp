#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[200001], b[200001];

bool solve(){
    for(int i=0;i<n;i++){
        if(a[i]!=b[i] && ((a[i]^a[i+1])!=b[i]) && ((a[i]^b[i+1])!=b[i]))
            return false;
    }
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--){

        cin >> n;

        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        a[n] = b[n] = 0;
        cout << (solve()? "YES" : "NO" ) << "\n";
    }
    return 0;
}

