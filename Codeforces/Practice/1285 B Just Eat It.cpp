#include <bits/stdc++.h>

using namespace std;

int a[100000];

bool solve(){

    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];

    long long acc = 0;
    for(int i=0;i<n;i++){
        acc+= a[i];
        if(acc <=0) return 0;
    }

    acc = 0;
    for(int i=n-1;i>=0;i--){
        acc+= a[i];
        if(acc <=0) return 0;
    }
    return 1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        cout << ( solve()? "YES" : "NO " ) << "\n";

    return 0;
}

