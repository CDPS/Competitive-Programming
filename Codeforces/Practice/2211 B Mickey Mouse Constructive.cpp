#include <bits/stdc++.h>

using namespace std;

int t = 1, x, y;

int f(int x){

    if(x==0) return 1;

    int ans = 0;
    for(int p=1; p*p <=x; p++)
        if(x%p == 0 )
            ans++, ans += x/p!= p;

    return ans;
}

void solve(){

    cin >> x >> y;

    int sum = abs(x-y);

    cout << f(sum) << "\n";
    for(int i=0; i <x; i++) cout << 1 << " ";
    for(int i=0; i<y; i++) cout << -1 << " ";
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
