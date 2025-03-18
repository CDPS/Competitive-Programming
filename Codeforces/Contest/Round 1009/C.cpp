#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[3];
bool check(){
    return (a[0]+a[1] > a[2]) && (a[0]+a[2]>a[1]) && (a[1]+a[2]>a[0]) ;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){

        cin >> a[1]; a[0] =0;
        for(int i=0;i<=30;i++)
            if(((1ll<<i)<=a[1]))
                a[0]|=(1ll<<i);
            else
                a[0]&= ~(1ll << (i-1) );

        a[2] = a[0]^a[1];

        cout << (check()? a[0] : -1 ) << "\n";
    }
    return 0;
}
