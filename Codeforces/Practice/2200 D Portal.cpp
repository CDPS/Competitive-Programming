#include <bits/stdc++.h>

using namespace std;

int t, n, x, y;

int a[200001];

void solve(){

    cin >> n >> x >> y;
    for(int i=1;i<=n;i++) cin >> a[i];

    int mini = n + 1, idx = x +  1;
    for(int i = x  + 1; i <= y; i++){
        if(a[i] < mini)
            mini = a[i], idx = i;
    }

    int idx2 = x + 1;
    for(int i=1;i <=x; i++){
        if(a[i] > mini ){
            idx2= i;
            break;
        }
        cout << a[i] << " ";
    }

    if(idx2 > x){
        for(int i=y+1;i <=n; i++){
            if(a[i]  > mini ){
                idx2= i;
                break;
            }
            cout << a[i] << " ";
        }
    }

    for(int i= idx; i <= y; i++)
        cout << a[i] << " ";
    for(int i= x + 1; i < idx ; i++)
        cout << a[i] << " ";

    if(idx2 <= x ){
        for(int i = idx2; i <= x; i ++ )
             cout << a[i] << " ";
        for(int i= y + 1; i <=n; i++)
            cout << a[i] << " ";
    }
    else if(idx2> y){
        for(int i = idx2; i <= n; i ++ )
             cout << a[i] << " ";
    }

    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}


