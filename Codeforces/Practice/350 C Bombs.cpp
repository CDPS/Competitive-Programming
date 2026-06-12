#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pii pair<int,int>

int t = 1, n, x, y;

map<char, char> dp = {
    {'R', 'L'},
    {'L', 'R'},
    {'U', 'D'},
    {'D', 'U'}
};

void process(pii pt){
    char dx = (pt.f < 0 )? 'L' : 'R';
    char dy = (pt.s < 0 )? 'D' : 'U';

    if (pt.f != 0)
        cout << 1 << " " << abs(pt.f) << " " << dx << "\n";
    if (pt.s != 0)
        cout << 1 << " " << abs(pt.s) << " " << dy << "\n";
    cout << 2 << "\n";
    if (pt.s != 0)
        cout << 1 << " " << abs(pt.s) << " " << dp[dy] << "\n";
    if (pt.f != 0)
        cout << 1 << " " << abs(pt.f) << " " << dp[dx] << "\n";
    cout << 3 << "\n";
}

void solve(){

    cin >> n;

    vector<pii> v(n);
    for(int  i = 0; i < n ;i++){
        cin >> x >> y;
        v[i].f = x;
        v[i].s = y;
    }

    sort(v.begin(), v.end(), [&](auto &a, auto &b){
        return (abs(a.f) + abs(a.s)) < (abs(b.f) + abs(b.s));
    });

    int acc = n * 2;
    for(auto p : v) {
        if(p.f != 0) acc += 2;
        if(p.s != 0) acc += 2;
    }

    cout << acc << "\n";
    for(auto p : v)
        process(p);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
