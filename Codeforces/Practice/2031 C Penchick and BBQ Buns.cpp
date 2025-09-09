#include <bits/stdc++.h>

using namespace std;

void solve(){

    int n;
    cin >> n;

    if(n%2  && n < 26){
        cout << -1 << "\n";
        return;
    }

    int init = 0;
    if(n%2){
        cout << "1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2" << " ";
        init = 13;
    }

    for(int i=init;i<n/2;i++)
        cout << i + 1 << " " << i + 1 << " \n"[i+1==n/2];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}
