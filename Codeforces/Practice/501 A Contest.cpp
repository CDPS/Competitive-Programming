#include <bits/stdc++.h>

using namespace std;

int t = 1, a, b, c, d;

int f(int p, int t){
    return max( (3*p)/10, p - (p/250)  * t );
}

void solve(){

    cin >> a >> b >> c >> d;

    int score_v = f(a, c);
    int score_m = f(b, d);

    if(score_v < score_m)
        cout << "Vasya" << "\n";
    else if(score_m < score_v)
        cout << "Misha" << "\n";
    else
        cout << "Tie" << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}

