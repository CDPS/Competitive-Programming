#include <bits/stdc++.h>

using namespace std;

bool a[101];

int main(){

    int n,m,k,x;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> k;
        while(k--)
            cin >> x, a[x] = true;
    }

    bool ans = true;
    for(int i=1;i<=m && ans;i++)
        ans = a[i] == true;
    cout << ((ans)? "YES" : "NO" ) << "\n";
}
