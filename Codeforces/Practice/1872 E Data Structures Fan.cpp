#include <bits/stdc++.h>

using namespace std;

int    a[100001];
int xsfx[100001];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, m, op, l, r; string s;

    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i], xsfx[i+1] = a[i] ^ xsfx[i];
        cin >> s;

        int xz = 0, xo = 0;
        for(int i=0;i<n;i++){
            if(s[i]== '0') xz^= a[i];
            else xo ^= a[i];
        }

        cin >> m;
        while(m--){
            cin >> op;
            if(op == 1){
                cin >> l >> r;
                xz^=  xsfx[r] ^ xsfx[l-1];
                xo^=  xsfx[r] ^ xsfx[l-1];

            }else{
                cin >> l;
                cout << (l==0? xz : xo ) << " ";
            }
        }
        cout << "\n";
    }


    return 0;
}
