#include <bits/stdc++.h>

using namespace std;

bool v[256];

int chop(int x){
    int ans=0;
    for(int i=0;i<8;i++)
         ans|=(x&(1<<i));
    return ans;
}

int main(){

    int t,n,m,x;

    cin >>t;

    while(t--){
        cin >> n >> m;
        memset(v,0, sizeof v);

        for(int i=0;i<n;i++)
            cin >> x, v[chop(x)]=1;

        while(m--){
            cin >> x;
            int ans  = 0;
            for(int i= 0;i<256;i++)
                if(v[i]) ans = max(ans, x&i);
            cout  << ans << "\n";
        }
    }
    return 0;
}
