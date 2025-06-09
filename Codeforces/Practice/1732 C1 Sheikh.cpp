#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll     a[100001];
ll  ssfx[100001];
ll  xsfx[100001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, q, l , r;

    cin >> t;

    while(t--){

        cin >> n >> q;

        for(int i=0;i<n;i++){
            cin >> a[i];
            ssfx[i+1]= a[i] + ssfx[i];
            xsfx[i+1]= a[i] ^ xsfx[i];
        }

        cin >> l >> r;

        ll best = ssfx[r] - ssfx[l-1] - (xsfx[r] ^ xsfx[l-1]);

        ll sacc = 0, xacc = 0;
        int ldx = l, rdx = r;
        for(int i=l-1, j = l-1; j<r;j++){
            sacc+= a[j];
            xacc^= a[j];
            while(i <= j && sacc - xacc == best){
                if(j-i < rdx - ldx )
                    ldx = i + 1, rdx = j + 1;
                sacc-= a[i];
                xacc^= a[i++];
            }
        }

        cout << ldx << " " << rdx  << "\n";
    }

    return 0;
}

