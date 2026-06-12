#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
int a[200000];

void solve(){

    cin >> n;

    for(int i=0; i < n; i++) cin >> a[i];

    int target = n;
    for(int i=0;i<n;i++){
        if(a[i] != target)
            break;
        target--;
    }

    if( target == 0){
         for(int i=0; i < n; i++)
            cout  << a[i] << " \n"[i==n-1];
         return;
    }

    int idx = 0;
    for(int i=0;i<n;i++){
        if(a[i] == target ){
            idx = i;
            break;
        }
    }

    for(int i=0;i< n-target; i++)
        cout << a[i] << " ";
    for(int i=idx;i>= n-target; i--)
        cout << a[i] << " ";
    for(int i=idx+1;i<n; i++)
        cout << a[i] << " ";

    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
