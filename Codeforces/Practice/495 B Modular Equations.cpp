#include <bits/stdc++.h>

using namespace std;

int t = 1, a, b;

void solve(){

    cin >> a >> b;
    if(a == b){
        cout << "infinity" << "\n";
        return;
    }

    if(b > a ){
       cout <<  0  << "\n" ;
       return;
    }

    int mod = a - b, ans = 0;
    for(int f=1 ; f*f <= mod; f++){
        if( mod % f == 0){
            int f2 = mod/ f;
            ans += f > b;
            if(f2 != f)
                ans += f2 > b;
        }
    }
    cout << ans << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
