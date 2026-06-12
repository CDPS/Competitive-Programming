#include <bits/stdc++.h>

using namespace std;

int t = 1, a, b;

void solve(){

    cin >> a >> b;
    for(int a1= 1000000; a1>= b; a1--){
        int a2 = 3*a - b - a1;
        if(a2 <= b && abs(a1-a2) <= 1e6){
            cout << 3 << "\n";
            cout << a2<< " " << b << " " << a1 << "\n";
            return;
        }
    }
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
