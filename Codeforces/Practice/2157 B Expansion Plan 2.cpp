#include <bits/stdc++.h>

using namespace std;

int t, n, x, y;
string s;

bool solve(){

    cin >> n >> x >> y >> s;
    if(x < 0 ) x*= -1;
    if(y < 0 ) y*= -1;

    int count8 = 0, count4 = 0;
    for(int i=0; i < n; i++){
        if(s[i] == '8') count8++;
        if(s[i] == '4') count4++;
    }
    return max(x, y) <= n  &&  x + y <= count4 + (2*count8) ;
 }

int main(){

    cin.tie(NULL); cin.sync_with_stdio(false);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}


