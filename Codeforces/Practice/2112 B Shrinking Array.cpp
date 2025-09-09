#include <bits/stdc++.h>

using namespace std;

int a[1000];
int t, n;

int solve(){

    for(int i=0;i<n-1;i++)
        if(abs(a[i]-a[i+1]) <= 1)
            return 0;

    for(int i=1;i<n-1;i++){
        if(a[i] > a[i-1] && a[i] > a[i+1])
            return 1;
        if(a[i] < a[i-1] && a[i] < a[i+1])
            return 1;
    }

    return -1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >>t;
    while(t--){

        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];

        cout <<  solve()  << "\n";
    }
    return 0;
}

