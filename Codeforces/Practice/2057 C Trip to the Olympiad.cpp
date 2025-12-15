#include <bits/stdc++.h>

using namespace std;

int t, l, r;

void solve(){

    cin >> l >> r;

    int common = 0, idx = 30;
    for(int i=30;i>=0;i--){
        if( ((1<<i)&l) != ((1<<i)&r) ){
            idx = i; break;
        }
        common |= ((1<<i)&l);
    }

    int a = common | (1<<idx);
    int b = common | ((1<<idx)-1);

    if(a==r || b == r)
         cout << a << " " << b << " "  << l << "\n";
    else
        cout << a << " " << b << " "  << r << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();
}
