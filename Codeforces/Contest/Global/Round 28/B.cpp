#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;

        vector<int> a(n,0);
        int acc = 1;
        for(int i=k-1; i<n;i+=k)
            a[i] = acc++;

        for(int i=0;i<n;i++)
            if(a[i]==0) a[i] = acc++;

        cout << a[0];
        for(int i=1;i<n;i++)
            cout << " " << a[i];
        cout << "\n";
    }
    return 0;
}
