#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
int a[100000];

bool all_ones(){
    for(int i=0;i<n;i++)
        if(a[i]!= 1)
            return false;
    return true;
}

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    if(all_ones()){
        for(int i=0;i<n-1;i++)
            cout << 1 << " ";
        cout << 2  << "\n";
        return;
    }

    sort(a, a + n);

    cout << 1  << " ";
    for(int i=0; i < n -1; i++)
        cout << a[i] << " \n"[i==n-2];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
