#include <bits/stdc++.h>

using namespace std;

bool a[100];
int t,n;

bool solve(){
    for(int i=1;i<=n-1;i++)
        if((!a[i]&&a[i-1]&&a[i+1]))
            return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> n;

        a[0] = 0;
        for(int i=0;i<n-2;i++)
            cin >> a[i+1];
        a[n-1] = a[n-2];

        cout << ( solve()? "YES" : "NO") << "\n";
    }

    return 0;
}
