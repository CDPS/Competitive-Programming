#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n,m,x;

    while(cin >> n >> m){

        if(n == 0 && m ==0) break;

        unordered_set<int> st;

        while(n--)
            cin >> x, st.insert(x);

        int ans =0;
        while(m--){
            cin >> x;
            if(st.count(x)){
                ans++;
            }
        }

        cout << ans << "\n";

    }
    return 0;
}
