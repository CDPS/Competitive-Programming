#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x;
    cin >> t;
    while(t--){

        cin >> n;

        set<int> st;
        for(int i=0;i<n;i++)
            cin >> x, st.insert(x);

        cout << st.size()  << "\n";
    }

    return 0;
}
