#include <bits/stdc++.h>

using namespace std;

int t, n;

string s;

int solve(){

    cin >> n >> s;

    vector<int> pfx(n, 0);
    for(int i=0; i < n; i++){
        if(s[i] == '(') pfx[i]++;
        if(i > 0 ) pfx[i] += pfx[i-1];
    }

    int ans = -1;
    for(int i= 1; i < n-1; i++){
        if(s[i] == ')' && s[i+1] == '(' && pfx[n-1] - pfx[i+1] >= 1 )
            return n-2;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}

