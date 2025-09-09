#include <bits/stdc++.h>

using namespace std;

bool check(int a, int b){
    return a <= 2*b + 2;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, a, b, c, d;

    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        c-=a, d-=b;
        if(b > a) swap(a,b);
        if(d > c) swap(c,d);
        cout << ( check(a,b)&& check(c,d)? "YES" : "NO" ) << "\n";
    }
    return 0;
}
