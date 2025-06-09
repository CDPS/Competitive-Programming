#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[1002];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n;

    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];

    ll ans = 0, idx = 0;
    for(int i=0;i<n;i++){
        ll sum = a[i];
        for(int j=i-1, mini = a[i];j>=0;j--)
            mini = min(a[j], mini), sum  += mini;
        for(int j=i+1, mini = a[i];j <n; j++)
            mini = min(a[j], mini),sum  += mini;
        if(sum > ans )
            ans = sum, idx = i;
    }

    for(int i=idx-1, mini = a[idx];i>=0;i--)
        mini = min(a[i], mini), a[i] = mini;
    for(int i=idx+1, mini = a[idx];i <n; i++)
        mini = min(a[i], mini), a[i] = mini;

    for(int i=0;i<n;i++)
        cout << a[i] << " \n"[i==n-1];

    return 0;
}

