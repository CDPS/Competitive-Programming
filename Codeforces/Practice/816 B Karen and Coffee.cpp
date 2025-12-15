#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll  pfx[200002];
ll qpfx[200002];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, k, q, a, b;

    cin >> n >> k >> q;

    for(int i=0;i<n;i++){
        cin >> a >> b;
        pfx[a]++, pfx[b+1]--;
    }

    for(int i=1;i<=200001;i++){
        pfx[i]+=pfx[i-1];
        if(pfx[i] >= k)
            qpfx[i]=1;
        qpfx[i]+=qpfx[i-1];
    }

    while(q--){
        cin >> a >> b;
        cout << qpfx[b] - qpfx[a-1] << "\n";
    }

    return 0;
}
