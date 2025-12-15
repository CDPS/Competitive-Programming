#include <bits/stdc++.h>

using namespace std;

int t, n;
int color[5001];

bool check(){
    for(int i=2;i<=n;i++)
        if(color[i]!=color[i-1])
            return true;
    return false;
}

void solve(){

    cin >> n;
    for(int i=1;i<=n;i++) cin >> color[i];

    if(!check()){
        cout << "NO" << "\n";
        return;
    }

    int pivot = 1;
    cout << "YES" << "\n";
    for(int i=2;i<=n;i++)
        if(color[i] != color[1])
            cout << 1 << " " << i << "\n", pivot = i;

    for(int i=2;i<=n;i++)
        if(color[i] == color[1])
            cout << pivot << " " << i << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
