#include <bits/stdc++.h>

using namespace std;

int a[100];
int b[100];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n;
    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];

        int ans =0;
        for(int i=0;i<n-1;i++)
            if(a[i] > b[i+1]) ans+= a[i] - b[i+1];

        cout << ans+a[n-1]  << "\n";
    }
    return 0;
}
