#include <bits/stdc++.h>

using namespace std;

int a[3];
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n >> a[0] >> a[1] >> a[2];

        int acc= a[0] + a[1] + a[2];
        int div = n / acc ;
        int ans =  (div*3);
        int rest = n- (div*acc) ;

        if(rest ==0)
            cout << ans<< "\n";
        else if( a[0] >= rest)
            cout << ans +1<< "\n";
        else if( a[0] + a[1] >= rest)
            cout << ans +2<< "\n";
        else
            cout << ans +3 << "\n";

    }
    return 0;
}

