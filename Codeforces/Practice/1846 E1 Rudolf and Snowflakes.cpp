#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;

set<int> st;

void process(){
    for(int i=2;i<=1000;i++){
        int acc = 1 + i + i*i;
        int pw = i*i;
        while(acc <= MAX){
            st.insert(acc);
            pw*=i;
            acc+= pw;
        }
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    process();

    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        cout << ( st.count(n)? "YES" : "NO" ) << "\n";
    }

    return 0;
}
