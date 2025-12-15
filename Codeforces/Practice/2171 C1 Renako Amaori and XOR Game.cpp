#include <bits/stdc++.h>

using namespace std;

int t, n;
bool a[200001];
bool b[200001];

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int idx = -1, acc=0;
    for(int i=0;i<n;i++)
        if(a[i] != b[i])
            idx = i, acc++;

    if(acc %2==0){
        cout << "Tie" << "\n";
        return;
    }

    cout << (idx%2==0? "Ajisai" : "Mai") << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}

