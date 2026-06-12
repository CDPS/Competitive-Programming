#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int solve(){

    cin >> n >> s;

    int ones =0, zeroes = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '1' ) ones++;
        else  zeroes++;
    }
    return abs(ones - zeroes);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
