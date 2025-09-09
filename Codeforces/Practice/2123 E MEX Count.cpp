#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;
    cin >> t;

    while(t--){

        cin >> n;

        vector<int> a(n+1,0);
        for(int i=0;i<n;i++) cin >> x, a[x]++;

        int mex  = 0;
        while(a[mex]>0) mex++;

        vector<int> pfx(n+2, 0);

        for(int i=0;i<=mex;i++){
            if(a[i]<=n-i)
                pfx[a[i]]++, pfx[n-i+1]--;
        }

        for(int i=1;i<=n;i++) pfx[i]+=pfx[i-1];

        for(int i=0;i<=n;i++)
            cout << pfx[i] << " \n"[i==n];
    }
    return 0;
}
