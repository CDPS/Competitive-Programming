#include <bits/stdc++.h>

using namespace std;

int t = 1;
int xs, ys, xt, yt;

int rook(){
    return (xs == xt || ys == yt) ?  1 : 2;
}

int bishop(){
    if(  (xs + ys)%2 != (xt + yt)%2 )
        return 0;
    return 1  +  ( abs(ys-yt) != abs(xs-xt));
}

int king(){
    return  max(abs(xs - xt), abs(ys - yt));
}

void solve(){

    cin >> xs >> ys >> xt >> yt;
    cout << rook() << " " << bishop() << " " << king() << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;;
}
