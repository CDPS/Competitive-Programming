#include <bits/stdc++.h>

using namespace std;

int t, n;

int   a[200001];
int   b[200001];
int pfx[2];

void solve(){

    cin >> n;

    pfx[0] = pfx[1] = 0;
    for(int i=0;i < n; i++) cin >> a[i], pfx[0]^= a[i];
    for(int i=0;i < n; i++) cin >> b[i], pfx[1]^= b[i];

    for(int i=0; i < n ; i++){

        int me = i%2;
        int other = !me;

        int my_pfx = pfx[me] ^ a[i] ^ b[i];
        int other_pfx = pfx[other] ^ a[i] ^ b[i];

        if(pfx[other] >  pfx[me]){
            if( other_pfx - my_pfx  < pfx[other] - pfx[me] )
                pfx[other] = other_pfx, pfx[me]    = my_pfx;
        }
        else {
            if( my_pfx - other_pfx > pfx[me] - pfx[other])
                pfx[other] = other_pfx, pfx[me]    = my_pfx;
        }
    }

    if(pfx[0] > pfx[1])
        cout << "Ajisai" << "\n";
    else  if(pfx[0] < pfx[1])
        cout << "Mai" << "\n";
    else
         cout << "Tie" << "\n";
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}



