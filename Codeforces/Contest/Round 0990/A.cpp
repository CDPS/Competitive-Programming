#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    set<int> st;
    for(int i=1;i*i<=100000;i+=2)
        st.insert(i*i);

    int t,n;
    cin >> t;

    while(t--){

        cin >> n;

        int acc=0,x, ans =0 ;
        for(int i=0;i<n;i++){
            cin >>x ;
            if(st.count(acc+=x)) ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}
