#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sfx[200001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    for(int i=1;i<=200000;i++){
        int x  = i, acc =0;
        while(x)
            x/=3, acc++;
        sfx[i] = acc + sfx[i-1];
    }

    int t, l, r;

    cin >> t;
    while(t--){
        cin >> l >> r;
        cout << sfx[r] + sfx[l]- (sfx[l-1]*2)  << "\n";
    }
    return 0;
}
