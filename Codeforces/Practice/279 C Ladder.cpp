#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m, l, r;

int    a[100002];
int  top[100002];
int down[100002];

void solve(){

    cin >> n >> m;

    for(int i=1;i<=n;i++)
        cin >> a[i], top[i] = i, down[i] = i;

    down[n] = top[n] = n ;
    for(int i=n-1;i>=1;i--){
        if(a[i]>= a[i+1])
            down[i] = down[i+1];
        if(a[i]<= a[i+1])
            top[i] = top[i+1];
    }

    while(m--){
        cin >> l >> r;
        cout << (( r <= down[ top[l] ]  )? "Yes" : "No" )<< "\n";
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}

