#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, q, m;
    string s;
    cin >> n >> s >> q;

    char c;
    while(q--){

        cin >> m >> c;

        int ans = 0, acc = 0;
        for(int i=0, j = 0; j < n ; j++){
            if(s[j]!= c) acc++;
            while(i < n &&  acc > m)
                acc = (s[i++]!=c)? acc-1 : acc;
            ans= max(ans, j-i+1);
        }
        cout << ans  << "\n";
    }

    return 0;
}
